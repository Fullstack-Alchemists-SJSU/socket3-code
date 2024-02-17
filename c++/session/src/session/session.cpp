#include <iostream>
#include <sstream>
#include <thread>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <time.h>

#include "session.hpp"
#include "../payload/builder.hpp"

#define BUFFER_SIZE 2048

using namespace std;

// Copy constructor
Session::Session(const Session& from): descriptor(from.descriptor), count(from.count){}


// Overload = operator
Session& Session::operator=(const Session& from){
  this->descriptor = from.descriptor;
  this->count = from.count;
  return *this;
}

void Session::increment(unsigned long by){
  if(by > 0){
    this->count += by;
  }
}

void Session::updateLastTime(){
  this->lastTime = time(NULL);
}

SessionHandler::SessionHandler(){
  this->isActive = true;
  this->refreshRate = 0;
}

void SessionHandler::addSession(int socketDescriptor){
  Session newSession(socketDescriptor, 0);
  this->sessions.emplace_back(move(newSession));
}

void SessionHandler::start(){
  this->sessionThread = make_shared<thread>([this]{
    run();
  });
}

void SessionHandler::stop(){
  this->isActive = false;
  for(auto& iterator : this->sessions){
    Session& currentSession = iterator;
    
    try{
      if(currentSession.descriptor >= 0){
        close(currentSession.descriptor);
      }
    }catch(...){
      cerr << "Error:" << endl << "Error in stop" << endl;
    }

    currentSession.descriptor = -1;
  }

  this->sessions.clear();

  try{
    this->sessionThread->join();
  }catch(...){
    cout << "Error:" << endl << "Error in join" << endl;
  }
}

vector<string> SessionHandler::splitter(Session& currentSession, const char* raw, int messageLength){
  vector<string> results;

  if(raw == NULL || messageLength <= 0){
    return results;
  }

  #ifdef CPLUSPLUSONLY
    const char* pointer =  raw;
    while(*pointer){
      results.push(pointer);
      pointer += results.back().length() + 1;
    }
  #else
    if(sDebug > 2){
      cerr << "sDebug is > 2" << "\t message: " << raw << endl;
    }

    auto position = 0;
    auto *pointer = &raw[0];
    while(position < messageLength){
      try{
        
        if((messageLength - position) < 5) {
          position = messageLength;
          continue;
        }

        string temp = string(&pointer[position], 0, 4);
        int messageLengthFromHeader = stoi(temp);

        if(messageLengthFromHeader > (messageLength - (position + 5))){
          position = messageLength;
          continue;
        }

        auto message = string(&pointer[position], 0, messageLengthFromHeader + 5);
        position += 5 + messageLengthFromHeader;

        if(position <= messageLength + 1){
          if(sDebug > 1){
            cerr << "New Message: " << message << endl;
          }

          results.push_back(message);
          while(pointer[position] == '\0' && position < messageLength){
            position++;
          }
        }

      }catch(const exception &e){
        stringstream error;
        error << "Error:" << endl << "Error in parsing raw message" << endl << e.what() << endl;
        throw runtime_error(error.str());
      }
    }

    if(sDebug > 1){
      cerr << "Got " << results.size() << " messages." << endl;
    }
  #endif

  return results;
}

void SessionHandler::process(const vector<string>& results){
  BasicBuilder builder;
  for(auto encodedMessage : results){
    auto message = builder.decode(encodedMessage);
    cerr << "Message group: " << message.group() << " name: " << message.name() << " text: " << message.text() << endl;
    cerr.flush();
  }
}



bool SessionHandler::cycle(){
  bool idle = true;
  char raw[BUFFER_SIZE] = { 0 };
  for(auto& currentSession : this->sessions){
    if(currentSession.descriptor == -1){
      continue;
    }

    cout << "current session: " << currentSession.descriptor << " lastTime: " << currentSession.lastTime << endl;

    if(currentSession.lastTime == 0){
      currentSession.updateLastTime();
    }

    if((time(NULL) - currentSession.lastTime) >= 60){
      cerr << "*** Force close a client due to last message timeout, id:" << currentSession.descriptor << ", count: " << currentSession.count << endl;
      auto currentDescriptor = currentSession.descriptor;

      this->sessions.erase(remove_if(this->sessions.begin(), this->sessions.end(), [&currentDescriptor](const Session& s){
              return s.descriptor == currentDescriptor;
            }
          ), 
        this->sessions.end()
      );

    }

    memset(raw, 0, BUFFER_SIZE);

    auto messageLength = read(currentSession.descriptor, raw, BUFFER_SIZE - 1);

    if(sDebug > 0 && messageLength > 0){
      cerr << "Debug info: " << endl << " descriptor: " << currentSession.descriptor << " length: " << messageLength << " errno: " << errno << endl;
    }

    if(messageLength > 0){

      cout << "currentSession: " << currentSession.descriptor << " last time: " << currentSession.lastTime << " current time: " << time(NULL) << endl;

      idle = false;
      auto results = splitter(currentSession, raw, messageLength);
      currentSession.increment(results.size());
      currentSession.updateLastTime();
      process(results);
      results.clear();

    }else if(messageLength == -1){

      if(errno == ECONNRESET){
        cerr << "*** A session was closed, id:" << currentSession.descriptor << ", count: " << currentSession.count << endl;
        auto currentDescriptor = currentSession.descriptor;

        this->sessions.erase(remove_if(this->sessions.begin(), this->sessions.end(), [&currentDescriptor](const Session& s){
                return s.descriptor == currentDescriptor;
              }
            ), 
          this->sessions.end()
        );

        idle = false;
        break;
      }
    }
  }

  return idle;
}

void SessionHandler::optimizeAndWait(bool idle){
  if(idle){
    
    if(this->refreshRate < 3000){
      this->refreshRate += 250;
    }
    
    if(sDebug > 0){
      cerr << this->sessions.size() << " sessions active, sleeping " << this->refreshRate << " ms" << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(this->refreshRate));
  }else{
    this->refreshRate = 0;
  }
}

void SessionHandler::run(){
  while(this->isActive){
    auto idle = true;
    try{

      idle = cycle();
    }catch(const exception &e){
      cerr << "Error: Aborting handler failure" << endl << e.what() << endl;

      if(sDebug > 0){
        abort();
      }
    }

    optimizeAndWait(idle);
  }
}

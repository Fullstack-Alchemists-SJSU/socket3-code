#include <iostream>
#include <iomanip>
#include <sstream>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include "sys/socket.h"
#include "socket/server.hpp"
#include "payload/builder.hpp"
#define BUFFER_SIZE 2048

using namespace std;

int main(){

  int clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(2001);
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  int connectSuccess = connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
  if(connectSuccess < 0){
    cerr << "Failed to connect to socket server" << endl;
    exit(EXIT_FAILURE);
  }
 
  for(int i = 0; i < 10000; i++){

    Message message("name 1", "group 1", "Sample , Text");
    BasicBuilder builder;

    auto payload = builder.encode(message);
    auto payloadLength = payload.length();


    cout << "Writing payload: " << payload.c_str() << endl;

    auto messageWrite = write(clientSocket, payload.c_str(), payloadLength);

    if(messageWrite == -1){
      cerr << "Error:" << endl << "Failed to send message with errno: " << errno << endl;
    }else if(errno == ETIMEDOUT){
      cout << "Timed out" << endl;
    }else if(payload.length() != (size_t)messageWrite){
      stringstream error;
      error << "Failed to fully write " << errno << endl;
      throw runtime_error(error.str());
    }else{
      cerr << "Wrote " << payload << " with size: " << payloadLength << ", errno: " << errno << endl;
    }
  }

  close(clientSocket);
  
  return 0;
}

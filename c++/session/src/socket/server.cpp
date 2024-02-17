#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cerrno>
#include <fcntl.h>
#include "sys/socket.h"
#include "server.hpp"
#define BUFFER_SIZE 1024

using namespace std;

SocketServer::SocketServer(string ip, signed int port){
  this->ip = ip;
  this->port = port;
  this->isActive = false;
  this->server = -1;
}

void SocketServer::start(){
  cout << "Connecting..." << endl;
  configure();

  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(this->port);
  socklen_t addressLength = sizeof(address);

  cout << "Waiting for connections..." << endl;

  while(this->isActive){

    int newConnection = accept(this->server, (struct sockaddr*)&address, &addressLength);
    if(newConnection < 0){
      stringstream error;
      error << "Connection refused with errorno: " << errno << endl;
      throw runtime_error(error.str());
    }

    int opt = 2;
    setsockopt(newConnection, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    fcntl(newConnection, F_SETFL, O_NONBLOCK);
    ioctl(newConnection, FIONBIO, (char *)&opt);

    sessionHandler.addSession(newConnection);
  }
}

void SocketServer::stop(){
  this->isActive = false;
  this->sessionHandler.stop();
  
  if(this->server > 0){
    close(this->server);
    this->server = -1;
  }
}

void SocketServer::configure(){
  cout << "Configuring host: " << this->ip << " on port: " << this->port << endl;

  this->server = socket(AF_INET, SOCK_STREAM, 0);
  if(this->server < 0){
    stringstream error;
    error << "Failed to create socket with errno:" << errno << endl;
    throw runtime_error(error.str());
  }


  int opt = 1;
  int setOptSuccess = setsockopt(this->server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

  if(setOptSuccess < 0){
    stringstream error;
    error << "Failed to set socket options with errorno" << errno << endl;
    throw runtime_error(error.str());
  }


  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(this->port);
  socklen_t addressLength = sizeof(address);

  int bindSuccess = bind(this->server, (struct sockaddr*) &address , sizeof(address));
  if(bindSuccess < 0){
    stringstream error;
    error << "Failed to bind socket with errorno" << errno << endl;
    throw runtime_error(error.str());
  }

  int listenSuccess = listen(this->server, 10);
  if(listenSuccess < 0){
    stringstream error;
    error << "Failed to listen with errorno: " << errno << endl;
    throw runtime_error(error.str());
  }
  cout << "Listening..." << endl;

  this->sessionHandler.start();
  this->isActive = true;
}

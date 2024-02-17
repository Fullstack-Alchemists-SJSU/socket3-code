#ifndef SOCKET_SERVER
#define SOCKET_SERVER

#include <iostream>
#include "../session/session.hpp"

using namespace std;

class SocketServer{

  private:
    string ip;
    signed int port;
    int server;
    bool isActive;
    SessionHandler sessionHandler;

  public:
    /**
      * Default constructor for localhost
     **/
    SocketServer(): ip("127.0.0.1"), port(2001), isActive(true), server(-1){}

    /**
      * Constructor for IP address which is not localhost
     **/
    SocketServer(string ip, signed int port);

    virtual ~SocketServer(){
      stop();
    }

    int getPort() const {
      return this->port;
    }

    string getIp() const {
      return this->ip;
    }

    void start();
    
    void stop();
    
    void configure();

};
#endif // !SOCKET_SERVER

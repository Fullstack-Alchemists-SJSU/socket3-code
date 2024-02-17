#include "socket/server.hpp"
#include <iostream>

using namespace std;

int main(){

  SocketServer socketServer;

  cout << "Port: " << socketServer.getPort() << " ip: " << socketServer.getIp() << endl;
  socketServer.start();

  return 0;
}

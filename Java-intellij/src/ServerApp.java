import socket.BasicServer;

/**
 * server application
 * 
 * @author gash
 * 
 */
class ServerApp {
	public ServerApp() {
	}

	public static void main(String[] args) {
		var host = "127.0.0.1";
		var port = 2001;
		var server = new BasicServer(host,port);
		server.start();
	}
}

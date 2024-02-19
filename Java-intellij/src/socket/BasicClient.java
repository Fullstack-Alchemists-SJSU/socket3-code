package socket;

import payload.BasicBuilder;
import payload.Message;

import java.io.IOException;
import java.net.Socket;

public class BasicClient {
	private String name;
	private String ipaddr;
	private int port;
	private String group = "public";

	private Socket clt;

	public BasicClient(String name) {
		this(name, "127.0.0.1", 2000);
	}

	public BasicClient(String name, String ipaddr, int port) {
		this.name = name;
		this.ipaddr = ipaddr;
		this.port = port;
	}

	public void stop() {
		if (this.clt != null) {
			try {
				this.clt.close();
			} catch (IOException e) {
				// TODO better error handling? yes!
				e.printStackTrace();
			}
		}
		this.clt = null;
	}

	public void join(String group) {
		this.group = group;
	}

	public void connect() {
		if (this.clt != null) {
			return;
		}

		try {
			this.clt = new Socket(this.ipaddr, this.port);
			System.out.println("Connected to " + clt.getInetAddress().getHostAddress());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void sendMessage(String message) {
		/*
		 * if (this.clt == null) { System.out.println("no connection, text not sent");
		 * return; }
		 */
		try {
			BasicBuilder builder = new BasicBuilder();
			Message newMessage = new Message(name, group, message);
			byte[] msg = builder.encode(newMessage).getBytes();
			System.out.println("New message before encoding: " + newMessage.toString());
			for(int i = 0; i < msg.length; i++) {
				System.out.print(msg[i]);
			}
			System.out.println("\n");
			System.out.println("Writing message: " + msg);
			this.clt.getOutputStream().write(msg);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}

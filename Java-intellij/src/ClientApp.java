import socket.BasicClient;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * client - basic chat construct. This varies from our Python and C++ versions
 * as it prompts the use for messages.
 * 
 * @author gash
 * 
 */
public class ClientApp {
	private BasicClient myClient;

	public ClientApp() {
	}

	public static void main(String[] args) {
		var myClient = new BasicClient("name 1", "127.0.0.1", 2001);
		myClient.connect();
		myClient.join("group 1");

		var br = new BufferedReader(new InputStreamReader(System.in));
		while (true) {
			try {
				System.out.print("\nenter message ('exit' to quit): ");
				var m = br.readLine();
				if(m.isEmpty()){
					System.out.println("Cannot send empty message!");
					break;
				}
				if (m.equalsIgnoreCase("exit")){
					System.out.println("Exit message received");
					break;
				}

				myClient.sendMessage(m);
			} catch (Exception ex) {
				break;
			}
		}
		
		myClient.stop();
	}
}
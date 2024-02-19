package payload;
/**
 * the builder to construct commands that both the client (BasicSocketClient)
 * and server (BasicServer) understands/accepts
 * 
 * @author gash
 * 
 */
public class BasicBuilder {

	public BasicBuilder() {
	}

	public String encode(Message msg) {
		var sb = new StringBuilder();
		//sb.append(msg.getGroup()).append(",").append(msg.getName()).append(",").append(msg.getText());
		
		StringBuilder temp = new StringBuilder();
		temp.append(msg.getGroup()).append(",").append(msg.getName()).append(",").append(msg.getText()); 
		
		String messageLength = String.format("%04d", temp.toString().length());
		sb.append(messageLength).append(",").append(temp);

		return sb.toString();
	}

	public Message decode(byte[] raw) throws Exception {
		if (raw == null || raw.length == 0)
			return null;

		try{
			var s = new String(raw);

			var parts = s.split(",", 4);
			var rtn = new Message(parts[2], parts[1], parts[3]);

			return rtn;
		}catch(Exception e) {
			System.out.println("Malformed message");
			return new Message("", "", "");
		}
	}
}

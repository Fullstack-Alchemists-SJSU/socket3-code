package socket;

import payload.BasicBuilder;
import payload.Message;

import java.io.BufferedInputStream;
import java.io.InterruptedIOException;
import java.net.Socket;


/**
 * @author gash
 */
class SessionHandler extends Thread {
    private Socket connection;
    private String name;
    private volatile boolean forever = true;


    public SessionHandler(Socket connection) {
        this.connection = connection;

        // allow server to exit if
        this.setDaemon(true);
    }

    /**
     * stops session on next timeout cycle
     */
    public void stopSession() {
        forever = false;
        if (connection != null) {
            try {
                connection.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        connection = null;
    }

    /**
     * process incoming data
     */
    public void run() {
        System.out.println("Session " + this.getId() + " started");

        try {
            connection.setSoTimeout(2000);

            try (BufferedInputStream inputStream = new BufferedInputStream(connection.getInputStream())) {
                byte[] raw = new byte[2048];
                BasicBuilder builder = new BasicBuilder();
                while (forever) {
                    try {
                        int len = inputStream.read(raw);
                        if (len == 0)
                            continue;
                        else if (len == -1)
                            break;

                        Message msg = builder.decode(new String(raw, 0, len).getBytes());
                        System.out.println(msg);

                    } catch (InterruptedIOException ioe) {
                        ioe.printStackTrace();
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            System.out.println("Session " + this.getId() + " ending");
            System.out.flush();
            stopSession();
        }
    }

} // class SessionHandler
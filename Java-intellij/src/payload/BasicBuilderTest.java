package payload;

import org.junit.Test;

import java.nio.charset.StandardCharsets;

public class BasicBuilderTest {

    String testName = "testName", testGroup = "testGroup", testMessage = "This is a test message";

    String VALIDATOR = "0041,testGroup,testName,This is a test message";

    BasicBuilder builder = new BasicBuilder();
    @Test
    public void encode() {
        String encodedMessage = builder.encode(new Message(testName, testGroup, testMessage));
        assert VALIDATOR.equals(encodedMessage);
    }

    @Test
    public void decode() {
        try{
            Message decoded = builder.decode(VALIDATOR.getBytes());
            assert decoded.getGroup().equals(testGroup);
            assert decoded.getName().equals(testName);
            assert decoded.getText().equals(testMessage);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
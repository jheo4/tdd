package basic;

import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.assertEquals;

public class TestSuiteCase2{
  String message = "Jin Heo";
  MessageUtil messageUtil = new MessageUtil(message);

  @Test
  public void testSalutationMessage(){
    System.out.println("Inside testPrintMessage()");
    message = "Hello!" + "Jin Heo";
    assertEquals(message, messageUtil.salutationMessage());
  }
}

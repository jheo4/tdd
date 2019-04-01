package basic;

import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.assertEquals;

public class TestSuiteCase1{
  String message = "Jin Heo";
  MessageUtil messageUtil = new MessageUtil(message);

  @Test
  public void testPrintMessage(){
    System.out.println("Inside testPrintMessage()");
    assertEquals(message, messageUtil.printMessage());
  }
}

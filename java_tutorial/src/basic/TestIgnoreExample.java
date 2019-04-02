package basic;

import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.*;

public class TestIgnoreExample{
  String message = "Jin Heo";
  MessageUtil messageUtil = new MessageUtil(message);

  @Ignore
  @Test
  public void testPrintMessage(){
    System.out.println("Ignored test message");
    message = "Jin Heo";
    assertEquals(message, messageUtil.printMessage());
  }

  @Test
  public void testSalutationMessage(){
    System.out.println("SalutationMessage Test");
    message = "Hello!" + "Jin Heo";
    assertEquals(message, messageUtil.salutationMessage());
  }
}

package basic;

import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.assertEquals;

public class TestTimeExample{
  String message = "Jin Heo";
  MessageUtil messageUtil = new MessageUtil(message);

  @Test(timeout = 300)
  public void testPrintMessage(){
    System.out.println("Test withtin 300 ms");
    for(int i = 0; i < 1000000; i++)
      System.out.print("");
    messageUtil.printMessage();
  }

  @Test(timeout = 50)
  public void testSalutationMessage(){
    System.out.println("Test within 100 ms");
    message = "Hello!" + "Jin Heo";
    for(int i = 0; i < 1000000; i++)
      System.out.print("");
    assertEquals(message, messageUtil.salutationMessage());
  }
}

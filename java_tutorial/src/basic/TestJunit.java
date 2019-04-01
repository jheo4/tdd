package basic;

import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class TestJunit{
  String message = "Hello JUnit";
  MessageUtil messageUtil = new MessageUtil(message);

  @Test
  public void testAdd(){
    assertEquals(message, messageUtil.printMessage());
  }
}

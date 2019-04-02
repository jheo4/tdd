package basic;

import org.junit.Test;

public class TestExceptionExample{
  ExceptionMaker exceptionMaker = new ExceptionMaker();

  @Test(expected = ArithmeticException.class)
  public void testDivideByZero(){
    System.out.println("Test divide by zero");
    exceptionMaker.divideByZero();
  }

  @Test
  public void testDivideByInteger(){
    System.out.println("Test divide by integer");
    exceptionMaker.divideByInteger();
  }
}

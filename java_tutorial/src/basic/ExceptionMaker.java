package basic;

public class ExceptionMaker{
  private int value = 10;

  public void divideByZero(){
    System.out.println("make an exception! divide value by 0");
    int exception = value/0;
  }

  public void divideByInteger(){
    System.out.println("non exception! divide value by a integer");
    int nonException = value/2;
  }
}

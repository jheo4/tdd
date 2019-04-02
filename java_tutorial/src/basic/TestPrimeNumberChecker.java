package basic;

import java.util.Collection;
import java.util.Arrays;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import static org.junit.Assert.assertEquals;

// annotated with @RunWith(Parameterized.class)
@RunWith(Parameterized.class)
public class TestPrimeNumberChecker{
  // instance variables for each column of test data
  private Integer inputNumber;
  private Boolean expectedResult;

  private PrimeNumberChecker primeNumberChecker;

  @Before
  public void initialize(){
    primeNumberChecker = new PrimeNumberChecker();
  }

  // public constructor which takes in what is equivalent to one row of test
  // data
  public TestPrimeNumberChecker(Integer inputNumber, Boolean expectedResult){
    this.inputNumber = inputNumber;
    this.expectedResult = expectedResult;
  }

  // create a public static method annotated with @Parameters which returns a
  // Collection of Objects as test data set
  @Parameterized.Parameters
  public static Collection primeNumbers(){
    return Arrays.asList(new Object[][]{
      {2, true},
      {6, false},
      {19, true},
      {22, false},
      {11111117, true},
      {111111179, false}
    });
  }

  @Test
  public void testPrimeNumberChecker(){
    System.out.println("parameterized number is : " + inputNumber);
    assertEquals(expectedResult, primeNumberChecker.validate(inputNumber));
  }
}

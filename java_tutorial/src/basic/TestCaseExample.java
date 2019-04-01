package basic;

import org.junit.Before;
import org.junit.After;
import org.junit.Test;
import junit.framework.*;


public class TestCaseExample extends TestCase{
  protected double fValue1;
  protected double fValue2;

  @Before
  protected void setUp(){
    fValue1 = 2.0;
    fValue2 = 3.0;
    System.out.println("[setUp] Hi...");
  }

  @Test
  public void testAdd(){
    System.out.println("# of Test Caes = " + this.countTestCases());

    String name = this.getName();
    System.out.println("Test Case Name = " + name);

    this.setName("testNewAdd");
    String newName = this.getName();
    System.out.println("Updated Test Case Name = " + newName);
  }

  @After
  protected void tearDown(){
    System.out.println("[tearDown] good bye...");
  }
}


package basic;

import org.junit.*;

public class TestAnnotation{
  @BeforeClass
  public static void beforeClass(){
    System.out.println("in before class");
  }

  @AfterClass
  public static void afterClass(){
    System.out.println("in after class");
  }

  @Before
  public void before(){
    System.out.println("in before test");
  }

  @After
  public void after(){
    System.out.println("in after test");
  }

  @Test
  public void test1(){
    System.out.println("I'm test1");
  }

  @Test
  public void test2(){
    System.out.println("I'm test2");
  }

  @Ignore
  @Test
  public void ingoreTest(){
    System.out.println("This test is ignored");
  }
}

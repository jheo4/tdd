package basic;

import org.junit.Test;
import static org.junit.Assert.*;

public class TestAssert{
  @Test
  public void testAdd(){
    String str1 = new String("abc");
    String str2 = new String("abc");
    String str3 = null;
    String str4 = "abc";
    String str5 = "abc";

    int val1 = 5;
    int val2 = 5;

    String[] expectedArray = {"one", "two", "three"};
    String[] resultedArray = {"one", "two", "threea"};

    assertEquals(str1, str2);
    assertEquals(str1, str4);
    assertSame(str4, str5);

    assertArrayEquals(expectedArray, resultedArray);
  }
}

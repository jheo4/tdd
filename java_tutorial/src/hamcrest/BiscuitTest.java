package hamcrest;

import org.junit.Test;
import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.*;

public class BiscuitTest{
  @Test
  public void testEquals(){
    Biscuit tempBiscuit = new Biscuit("Ginger");
    Biscuit myBiscuit = new Biscuit("Ginger");
    assertThat(tempBiscuit.type.toString(),
        equalTo(myBiscuit.type.toString()));
  }
}

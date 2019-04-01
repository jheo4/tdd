package basic;

import org.junit.Test;
import junit.framework.AssertionFailedError;
import junit.framework.TestResult;

public class TestResultExample extends TestResult{
  public synchronized void addError(Test test, Throwable t){
    super.addError((junit.framework.Test)test, t);
  }

  public synchronized void addFailure(Test test, AssertionFailedError t){
    super.addFailure((junit.framework.Test)test, t);
  }

  @Test
  public void testAdd(){
  }

  public synchronized void stop(){
  }
}

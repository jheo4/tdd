
package basic;

import org.junit.Test;
import org.junit.Before;
import static org.junit.Assert.assertEquals;

public class TestEmployeeDetails{
  EmployeeBusinessLogic employeeBusinessLogic = new EmployeeBusinessLogic();
  EmployeeDetails employee = new EmployeeDetails();

  @Before
  public void setUp(){
    employee.setName("JinHeo");
    employee.setAge(28);
    employee.setMonthlySalary(8000);
  }

  @Test
  public void testCalculateAppraisal(){
    double appraisal = employeeBusinessLogic.calculateAppraisal(employee);
    assertEquals(500, appraisal, 0.0);
  }

  @Test
  public void testCalculateYearlySalary(){
    double salary = employeeBusinessLogic.calculateYearlySalary(employee);
    assertEquals(salary, (double)8000*12, 0.0);
  }
}

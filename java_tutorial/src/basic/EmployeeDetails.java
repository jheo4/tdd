
package basic;

public class EmployeeDetails{
  private String name;
  private double monthlySalary;
  private int age;

  public String getName(){return name;}
  public int    getAge(){return age;}
  public double getMonthlySalary(){return monthlySalary;}

  public void setName(String name){this.name = name;}
  public void setAge(int age){this.age = age;}
  public void setMonthlySalary(int monthlySalary){
    this.monthlySalary = monthlySalary;
  }
}

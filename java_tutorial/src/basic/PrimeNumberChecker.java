package basic;

public class PrimeNumberChecker{
  public Boolean validate(final Integer primeNumberCandidate){
    for(int i = 2; i < (primeNumberCandidate)/2; i++){
      if(primeNumberCandidate % i == 0){
        return false;
      }
    }
    return true;
  }
}

#include <iostream>

bool isPrime(int n){
  //check for 0 & 1
  if(n <= 1) return false;
  
  //check for numbers that n divides into 
  for(int i=2; i <= n/2; i++){  // n/2 to optimize run time
    if(n % i == 0) return false;     
  }
  return true;
}

void printPrimes(int n){

  for(int i=0; i <= n; i++){
    if(isPrime(i)){
      std::cout << i << "  ";
    }
  }
  std::cout << std::endl;
}

int main(){
  
  int input;
  
  while(input != 1){
  std::cout << "Enter number: ";
  std::cin >> input ;
  printPrimes(input);
  }
  
  return 0;
}

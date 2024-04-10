#include <iostream>

int main(){
  
  int old = 0;
  int current = 1;
  int next = 0;
  for(int i=0; i < 10; i++){
    std::cout << current << "  ";
    
    next = old + current;
    old = current;
    current = next;
  }
  std::cout << std::endl;
  
  old = 0;
  current=1;
  next = 0;

  while(current < 100){
    std::cout << current << "  ";
    
    next = old + current;
    old = current;
    current = next;
  }
  std::cout << std::endl;
  
  
  return 0;
}

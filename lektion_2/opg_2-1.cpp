#include <iostream>
#include <array>


int main(){
  
  int age; 
  std::cout << "Enter age: ";
  std::cin >> age;

  if(age<3){
    std::cout << "Du kan komme gratis i Zoo" << std::endl;
  }
  
  if(age>=18){
    std::cout << "Du kan køre i bil" << std::endl;
  }
  
  for(int i=1; i <= age; i++){
    std::cout << i << " ";
  }
  std::cout << std::endl;
  
  
  std::array<int,10> myarray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  for(int i=0; i < myarray.size(); i++){
    std::cout << myarray[i] << " ";
  }
  std::cout << std::endl;
  
  for(int i : myarray){
    std::cout << i << " ";
  }  
  std::cout << std::endl;
  
  
  
  return 0;
}

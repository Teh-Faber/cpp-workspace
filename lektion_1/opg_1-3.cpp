#include <iostream>

int getYear(int x);
int getMonth(int x);
int getDay(int x);
int getQuater(int x);
void print(int x);

int main(){
  
  int x;
  
  //input
  std::cout << "Enter date in the format YYYYMMDD" << std::endl;
  std::cin >> x;
  
  //check if date is gregorian
  if (x >= 17000101 && x <=99991231){
    //output
    print(getYear(x));
    print(getMonth(x));
    print(getDay(x));
    print(getQuater(x));
 
  }else{
    std::cout << "The given date is not in the format YYYYMMDD or after the year 1700" << std::endl; 
  }
  
  return 0;
}

int getYear(int x){
  x = x/10000;
  return x;
}

int getMonth(int x){
  x = (x - getYear(x)*10000 )/100;
  return x;
}

int getDay(int x){
  x = x - getYear(x)*10000 - getMonth(x)*100;
  return x;
}

int getQuater(int x){
  x = getMonth(x)/3;
  return x;
}

void print(int x){
  std::cout << x << std::endl;
}

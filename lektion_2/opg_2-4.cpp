#include <iostream>
#include <string>

int getYear(int x);
int getMonth(int x);
int getDay(int x);
int getQuater(int x);
bool isLeapYear(int x);
bool isValid(int x);
int incrementDate(int x);
int differenceInDays(int x1, int x2);
int dayOfTheYear(int x);
int weekDay(int x);
std::string weekdayAsText(int weekday);

void print(int x);



int main(){
  
  int x;
  
 //input
  std::cout << "Enter date in the format YYYYMMDD: ";
  std::cin >> x;
  
 
 //output
  std::cout << "Year: ";
  print(getYear(x));
  
  std::cout << "Month: ";
  print(getMonth(x));
  
  std::cout << "Day: ";
  print(getDay(x));
  
  std::cout << "Quarter: ";
  print(getQuater(x));
  
  std::cout << "Is Leap Year: ";
  print(isLeapYear(x));
  
  std::cout << "Is Valid: ";
  print(isValid(x));
  
  std::cout << "Next day: ";
  print(incrementDate(x));
  
  std::cout << "Day of the year: ";
  print(dayOfTheYear(x));
  
  std::cout << "Day of the week: ";
  std::cout << weekdayAsText(weekDay(x)) << std::endl;
  
 //date difference
  int x1;
  std::cout << "Enter new date in the format YYYYMMDD: ";
  std::cin >> x1;
  
  std::cout << "Difference in days: ";
  print(differenceInDays(x, x1));
  
  return 0;
}


//functions

 int getYear(int x){
 	//get year by dividing with 10000
 	 return x/10000;
 }

 int getMonth(int x){
 	//get month by subtracting year
 	 return (x - getYear(x)*10000 )/100;
 }

 int getDay(int x){
 	//get day by subtracting year & month 
 	 return x - getYear(x)*10000 - getMonth(x)*100;
 }

 int getQuater(int x){
 	//get quater by dividing with 4 and rounding up to nearest int
 	 return (getMonth(x)+.5)/4. + 1;
 }

 bool isLeapYear(int x){
 	//check for leap year if divideble by 4 and not by 100, unless if by 4 & 100 & 400
 	 if((getYear(x)%4==0 && getYear(x)%100!=0) || (getYear(x)%4==0 && getYear(x)%100==0 && getYear(x)%400==0)){ 
 	   return true;
  	 }
  	 
 	 return false;
 }

 bool isValid(int x){
	 //check if date is not gregorian
	  if (x < 17000301 || x > 99991231) return false;
  
	 //check if day is lower than 1
	  if(getDay(x)<1) return false;
  	 
	 //check months and days in month are incorrect
	  switch(getMonth(x)){
	     default 	: return false; break;
	     case 1 	: if(getDay(x)>31) return false; break;
	     case 2 	: if(getDay(x)>28 && !isLeapYear(x) || getDay(x)>29) return false; break;//fuck this month
	     case 3 	: if(getDay(x)>31) return false; break;
	     case 4 	: if(getDay(x)>30) return false; break;
	     case 5 	: if(getDay(x)>31) return false; break;
	     case 6 	: if(getDay(x)>30) return false; break;
	     case 7 	: if(getDay(x)>31) return false; break;
	     case 8	: if(getDay(x)>31) return false; break;
	     case 9 	: if(getDay(x)>30) return false; break;
	     case 10 	: if(getDay(x)>31) return false; break;
	     case 11 	: if(getDay(x)>30) return false; break;
	     case 12 	: if(getDay(x)>31) return false; break;
	  }

	  return true;
 }

 int incrementDate(int x){ 	
 	//increment date by 1 until is valid
 	 do {
 	   x++;
 	 } while(!isValid(x));
 	 
 	 return x;
 }

 int differenceInDays(int x1, int x2){
 	 int i=0;
 	//check is dates are valid if not return 0
 	 if(isValid(x1) && isValid(x2)){
 	  //find if date 2 or date 1 is first
 	   if(x1 < x2){
 	    //increment x1 and i until date 2 is reached
 	     while(x1 < x2){
 	       x1 = incrementDate(x1);
 	       i++;
 	     }
 	   }else{
 	    //increment x2 and i until date 1 is reached
 	     while(x2 < x1){
 	       x2 = incrementDate(x2);
 	       i++;
 	     }
 	   }
 	 }
 	return i;
 }

 int dayOfTheYear(int x){
 	//find day of the year with difference from Jan 1st
 	 return differenceInDays((getYear(x)*10000)+101, x);
 }

 int weekDay(int x){
 	//find weekday from knowing 1700-03-01 was a monday (%7 + 1) for conversion to week
 	 return (differenceInDays(17000301,x)%7) + 1;
 }


 std::string weekdayAsText(int weekday){
	//assign weekday name to number
 	 switch(weekday){
 	    default 	: return "Error(Weekday not between 1-7)"; break;
 	    case 1 	: return "Mon"; break;
 	    case 2 	: return "Tue"; break;
 	    case 3 	: return "Wed"; break;
 	    case 4 	: return "Thu"; break;
 	    case 5 	: return "Fri"; break;
 	    case 6 	: return "Sat"; break;
 	    case 7 	: return "Sun"; break;
 	 }
 }

 void print(int x){
	 //print number to terminal
	  std::cout << x << std::endl;
 }

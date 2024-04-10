#ifndef DATE_H
#define DATE_H

#include <array>
#include <string>
#include <iostream>

class Date{
  private:
    int _x; //private date
    std::array<std::string, 7> _weekDays = {"mon", "tue", "wed", "thu", "fri", "sat", "sun"}; //weekday names
    int _firstDate   = 17000301; //first date in the gregorian calendar
    int _lastDate    = 99991231; //last date in the gregorian calendar


  public:
    Date(int x){
       //initialize _x to input
        _x = x;
       //check validity of date, set to firstDate if it isnt
        if(!isValid())  _x = _firstDate;
    }


    int getYear(){
       //get year by dividing with 10000
        return _x / 10000;
    }


    int getMonth(){
       //get month by subtracting year
        return (_x - getYear() * 10000) / 100;
    }


    int getDay(){
       //get day by subtracting year & month
        return _x - getYear() * 10000 - getMonth() * 100;
    }


    int getQuarter(){
       //get quarter by dividing with 4 and rounding up to nearest int
        return (getMonth() + .5) / 4. + 1;
    }


    bool isLeapYear(){
       //check for leap year if divisible by 4 & not by 100, unless by 4 & 100 & 400
        if((getYear() % 4 == 0 && getYear() % 100 != 0) || (getYear() % 4 == 0 && getYear() % 100 == 0 && getYear() % 400 == 0))
         return true;
        return false; //if it isn't
    }


    bool isValid(){
      //check if date is not gregorian
        if(_x < _firstDate || _lastDate < _x) return false;

      //check if day is lower than 1
        if(getDay() < 1) return false;

      //check months and amount of days in month are incorrect
        switch(getMonth()){
            default     : return false; break;
            case 1      : if(getDay() > 31) return false; break;
            case 2      : if(getDay() > 28 && !isLeapYear() || getDay() > 29 ) return false; break;//f this month
            case 3      : if(getDay() > 31) return false; break;
            case 4      : if(getDay() > 30) return false; break;
            case 5      : if(getDay() > 31) return false; break;
            case 6      : if(getDay() > 30) return false; break;
            case 7      : if(getDay() > 31) return false; break;
            case 8      : if(getDay() > 31) return false; break;
            case 9      : if(getDay() > 30) return false; break;
            case 10     : if(getDay() > 31) return false; break;
            case 11     : if(getDay() > 30) return false; break;
            case 12     : if(getDay() > 31) return false; break;
        }
        return true; //if all tests are passed
    }


    void incrementDate(){
       //increment date by 1 until it is valid
        do {
         _x++;
         
	   //for optimization
             //if day exceeds 31, move to the next month
              if (getDay() > 31)
                 _x += 100 - getDay()+1; //move to the 1st of next month

             //if month exceeds 12, move to the next year
              if (getMonth() > 12)
                 _x += 10000 - (getMonth() * 100) - getDay() + 101; //move to the 1st of 1st month of next year

        } while(!isValid());
        return;
    }


// 1700 12 31   + 10000 = 1701 12 31 - 12 - 31 + 101 = 1701 01 01

    int differenceInDays(Date future){
     //find the difference in days by incrementing for every valid day in between the dates
      int i     = 0;
      int og_x  = _x;     //save current date since _x will be overwritten by incrementDate

       //check for which date is earlier
        if(_x > future._x){
           //switch _x & future._x
             _x          = future._x;
             future._x   = og_x;
        }
        
       //increment _x and i until future._x is reached
        while(_x < future._x ){
             incrementDate();
             i++;
        }
        
        _x = og_x;    //restore _x
        return i;     //the amount of days between _x and future._x
    }


    int dayOfTheYear(){
       //find day of the year with differenceInDays from current date to Jan 1st (+1 since Jan 1st is the first day)
        return differenceInDays(Date(getYear() * 10000 + 101))+1;
    }


    int weekday(){
       //find weekday from knowing 1700-03-01 was a monday (%7 + 1) for conversion to week
        return (differenceInDays(Date(_firstDate))%7) + 1;
    }


    std::string weekdayAsText(int weekday){
       //assign weekday name to number
        return _weekDays[weekday-1];
    }


    void print(){
       //print number to terminal
        std::cout << weekdayAsText(weekday()) << " " << getDay() << "/" << getMonth() << "-" << getYear() << std::endl;
    }
};

#endif

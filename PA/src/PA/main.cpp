#include <iostream>
#include <string>
#include "date.h"


template <class T1>
void test(T1 test, T1 target, std::string msg){
    std::string equal = test==target ? "Success: " : "Failed:  ";
    std::cout << equal << msg << "\t " << test << " " << target << std::endl;
}

int main(int argc, char** argv )
{
    Date date(20210201); //2020 feb 1st
    test<int>(date.getYear(),  2021, "date.getYear()");
    test<int>(date.getMonth(), 2,    "date.getMonth()");
    test<int>(date.getDay(),   1,    "date.getDay()");

    std::cout << std::endl;

    Date y1900(19000101);
    Date y2000(20000101);
    Date y2004(20040101);
    Date y2005(20050101);
    test<bool>(y1900.isLeapYear(),false, "y1900.isLeapYear()");
    test<bool>(y2000.isLeapYear(),true , "y2000.isLeapYear()");
    test<bool>(y2004.isLeapYear(),true , "y2004.isLeapYear()");
    test<bool>(y2005.isLeapYear(),false, "y2005.isLeapYear()");

    std::cout << std::endl;


    Date jun12_2020(20200612);
    Date jun12_2021(20210612);
    Date jan01_2021(20210101);
    Date dec31_2020(20201231);
    Date dec31_2021(20211231);

    test<int>(jun12_2020.dayOfTheYear(), 164, "jun12_2020.dayOfTheYear()");
    test<int>(jun12_2021.dayOfTheYear(), 163, "jun12_2021.dayOfTheYear()");
    test<int>(jan01_2021.dayOfTheYear(), 1  , "jan01_2021.dayOfTheYear()");
    test<int>(dec31_2020.dayOfTheYear(), 366, "dec31_2020.dayOfTheYear()");
    test<int>(dec31_2021.dayOfTheYear(), 365, "dec31_2021.dayOfTheYear()");

    std::cout << std::endl;

    Date d1(20000229); // no  warning
    Date d2(20010229); //  warning
    Date d3(16532356); //  warning
    Date d4(20331121); // no  warning
    Date d5(123456789); // no  warning

    test<int>(d1.getYear()*10000 + d1.getMonth()*100 + d1.getDay(), 20000229, "test constructor");
    test<int>(d2.getYear()*10000 + d2.getMonth()*100 + d2.getDay(), 17000301, "test constructor"); //invalid input date. Set to 17000301
    test<int>(d3.getYear()*10000 + d3.getMonth()*100 + d3.getDay(), 17000301, "test constructor"); //invalid input date. Set to 17000301
    test<int>(d4.getYear()*10000 + d4.getMonth()*100 + d4.getDay(), 20331121, "test constructor");
    test<int>(d5.getYear()*10000 + d5.getMonth()*100 + d5.getDay(), 17000301, "test constructor"); //invalid input date. Set to 17000301
    std::cout << std::endl;

    Date oneDay(20210127);
    test<int>(oneDay.differenceInDays(Date(20210203)), 7, "oneDay.differenceInDays(Date(20210203))");
    test<int>(oneDay.differenceInDays(Date(20210201)), 5, "oneDay.differenceInDays(Date(20210201))");
    test<int>(oneDay.differenceInDays(Date(20220201)), 370, "oneDay.differenceInDays(Date(20220201))");

    std::cout << std::endl;

    Date da(20210202);
    Date db(20210305);
    Date dc(17000301);
    test<int>(da.weekday(),2,"da.weekday()");
    test<int>(db.weekday(),5,"db.weekday()");
    test<int>(dc.weekday(),1,"dc.weekday()");
    test<std::string>(da.weekdayAsText(da.weekday()),"tue","da.weekdayAsTexty()");
    test<std::string>(db.weekdayAsText(db.weekday()),"fri","db.weekdayAsTexty()");
    test<std::string>(dc.weekdayAsText(dc.weekday()),"mon","dc.weekdayAsTexty()");

    std::cout << std::endl;

    Date startDate(20201229);
    /* Correctly prints the dates 29,30,31 dec 2020 and 1,2,3,4 jan 2021 */
    for(int i=0; i<7; i++){
        startDate.print();
        startDate.incrementDate();
    }

}

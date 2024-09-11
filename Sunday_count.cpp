// Date: 2024-09-11
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;

// This problem will coun the # of month starts with sunday in given year. Provided that jan 1 of 1900 was monday.

bool isLeapYear(int year){
    return ((year % 4 == 0 && year % 100 != 0) || (year%400 == 0));
}

int sundayCount(int year){
    int day_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int day_of_week = 0; // 0 being Monday
    int yr;

    // Calculate day of week for 1st January of the target year (2024)
    for ( yr = 1900; yr < year; yr++){
        // Set February days based on leap year status
        if (isLeapYear(yr)){
            day_in_month[1] = 29;
        } else {
            day_in_month[1] = 28;
        }

        // Advance day_of_week for each month in the year
        for (int month = 0; month < 12; month++){  
            day_of_week += day_in_month[month];
            day_of_week = day_of_week % 7; // Wrap around to the week (0 to 6)
        }
    }

    // Now the year is 2024, and the 1st January starts on day_of_week
    int sunday_count = 0;
    
    // Set February days for the target year (2024)
    if (isLeapYear(year)){
        day_in_month[1] = 29;
    } else {
        day_in_month[1] = 28;
    }

    // Count how many months start with a Sunday in 2024
    for (int month = 0; month < 12; month++){
        if (day_of_week == 6) sunday_count++; // 6 means Sunday
        
        // Advance day_of_week for the next month
        day_of_week += day_in_month[month];
        day_of_week = day_of_week % 7;
    }

    return sunday_count;
}

int main() {

    cout << "sunday count in 2021 " << sundayCount(2021) << endl;
   

    return 0;
}
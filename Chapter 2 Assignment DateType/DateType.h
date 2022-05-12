//
// Created by Chris Simaan on 5/11/22.
//

#include <string>
#include "iostream"

using namespace std;

class DateType {
public:


    string monthString;

    void Initialize(int m, int d, int y) {
        m = month;
        d = day;
        y = year;

        if (month == 1) {
            monthString = "January";
        } else if (month == 2) {
            monthString = "February";
        } else if (month == 3)
            monthString = "March";
        else if (month == 4)
            monthString = "April";
        else if (month == 5)
            monthString = "May";
        else if (month == 6)
            monthString = "June";
        else if (month == 7)
            monthString = "July";
        else if (month == 8)
            monthString = "August";
        else if (month == 9)
            monthString = "September";
        else if (month == 10)
            monthString = "October";
        else if (month == 11)
            monthString = "November";
        else if (month == 12)
            monthString = "December";
        else {
            monthString = "";
        }
    };
    // Initializes month, day, and year.
    int GetMonth() const;
    // Returns month.
    int GetDay() const;
    // Returns day.
    int GetYear() const;

    void CalculateDays();

private:
    int month;
    int day;
    int year;
    int daysInMonth;

};
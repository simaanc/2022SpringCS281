//
// Created by Chris Simaan on 5/11/22.
//

#include "DateType.h"

void DateType::CalculateDays() {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            daysInMonth = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        case 2: {
            if (year % 4) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        }
    }
}

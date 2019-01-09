// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Edward Vuong       November 1, 2018
/////////////////////////////////////////////////////////////////

#include "Date.h"
#include <iostream>

using namespace std;

namespace aid {
    
    Date::Date() {
        year = 0;
        month = 0;
        date = 0;
        compare = 0;
        error = NO_ERROR;
    }
    
    Date::Date(int yr, int mo, int day) {
        if (yr >= min_year && yr <= max_year) {
            if (mo >= 1 && mo <= 12) {
                int compareValue = yr * 372 + mo * 31 + day;
                if (compareValue >= min_date) {
                    year = yr;
                    month = mo;
                    date = day;
                    compare = compareValue;
                    error = NO_ERROR;
                }
                else {
                    *this = Date();
                    error = PAST_ERROR;
                    compare = 0;
                }
                
            }
            else {
                *this = Date();
                error = MON_ERROR;
                compare = 0;
            }
        }
        else {
            *this = Date();
            error = YEAR_ERROR;
            compare = 0;
        }
    }
    
    void Date::errCode(int code) {
        error = code;
    }
    
    // number of days in month mon and year year
    int Date::mdays(int mon, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    
    bool Date::operator == (const Date& rhs) const {
        int rhsCompare = rhs.year * 372 + rhs.month * 31 + rhs.date;
        return this->compare == rhsCompare;
    }
    bool Date::operator != (const Date& rhs) const {
        int rhsCompare = rhs.year * 372 + rhs.month * 31 + rhs.date;
        return !(this->compare == rhsCompare);
    }
    bool Date::operator < (const Date& rhs) const {
        int rhsCompare = rhs.year * 372 + rhs.month * 31 + rhs.date;
        return this->compare < rhsCompare;
    }
    
    bool Date::operator > (const Date& rhs) const {
        int rhsCompare = rhs.year * 372 + rhs.month * 31 + rhs.date;
        return this->compare > rhsCompare;
    }
    
    bool Date::operator<=(const Date& rhs) const {
        int rhsCompare = rhs.year * 372 + rhs.month * 31 + rhs.date;
        return this->compare <= rhsCompare;
    }

    bool Date::operator>=(const Date& rhs) const {
        int rhsCompare = rhs.year * 372 + rhs.month * 31 + rhs.date;
        return this->compare >= rhsCompare;
    }
    
    int Date::errCode() const {
        return error;
    }
    
    bool Date::bad() const {
        return error == NO_ERROR;
    }
    
    std::istream& Date::read(std::istream& input) {
        char div;
        input.clear();
        input >> year >> div >> month >> div >> date;
        
        if (input.fail()) {
            *this = Date();
            errCode(CIN_FAILED);
        }
        else if (year > max_year || year < min_year) {
            *this = Date();
            errCode(YEAR_ERROR);
        }
        else if (month < 1 || month > 12) {
            *this = Date();
            errCode(MON_ERROR);
        }
        else if (date > mdays(month, year)) {
            *this = Date();
            errCode(DAY_ERROR);
        }
        else if ((year * 372 + month * 31 + date) < min_date) {
            *this = Date();
            errCode(PAST_ERROR);
        }
        return input;
    }
    
    std::ostream& Date::write(std::ostream& output) const {
        output << year << "/";
        //if month is 9 or less, it adds a 0 so it appears as 09
        if (month < 10)
            output << 0;
        output << month << "/";
        
        //if date is 9 or less, it adds a 0 so it appears as 09
        if (date < 10)
            output << 0;
        output << date;
        
        return output;
    }
    
    std::istream& operator>>(std::istream& input, Date& send) {
        return send.read(input);
    }
    
    std::ostream& operator<<(std::ostream& input, Date& send) {
        return send.write(input);
    }
    
}

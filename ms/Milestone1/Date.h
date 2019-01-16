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

#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace aid {
    
#define NO_ERROR 0
#define CIN_FAILED 1
#define DAY_ERROR 2
#define MON_ERROR 3
#define YEAR_ERROR 4
#define PAST_ERROR 5
    
    const int min_year = 2018;
    const int max_year = 2038;
    const int min_date = 751098;
    
    class Date {
        int year;
        int month;
        int date;
        int compare;
        int error;
        
        int mdays(int, int)const;
        void errCode(int);
        
    public:
        Date();
        Date (int, int, int);
        
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        
        int errCode() const;
        bool bad() const;
        
        std::istream& read (std::istream& istr);
        std:: ostream& write (std::ostream& ostr) const;
    };
    
    std::istream& operator>> (std::istream& istr, Date&);
    std::ostream& operator<<(std::ostream& ostr, Date&);
    
}
#endif

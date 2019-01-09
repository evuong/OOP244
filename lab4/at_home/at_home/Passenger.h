/**********************************************************
 // Workshop 4: Constructors
 // w4_in_lab.cpp
 // Edward Vuong 120246186
 // evuong1@myseneca.ca
 // Section G
 **********************************************************/


#ifndef Passenger_h
#define Passenger_h

#include <stdio.h>

namespace sict {
    class Passenger {
    private:
        char pass[19];
        char destination[19];
        int year;
        int month;
        int day;
    public:
        Passenger ();
        Passenger (const char*, const char*);
        Passenger (const char*, const char*, int, int, int);
        bool isEmpty () const;
        void display () const;
        const char* name () const;
        bool canTravelWith (const Passenger&) const;
    };
    
}






#endif

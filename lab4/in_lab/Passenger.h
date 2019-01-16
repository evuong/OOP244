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
        char name[19];
        char destination[19];
    public:
        Passenger ();
        Passenger (const char*, const char*);
        bool isEmpty () const;
        void display () const;
    };
    
}






#endif

/**********************************************************
 // Workshop 4: Constructors
 // w4_in_lab.cpp
 // Edward Vuong 120246186
 // evuong1@myseneca.ca
 // Section G
 **********************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Passenger.h"
    
using namespace std;

namespace sict {
    
    //safe state
    Passenger::Passenger() {
        pass[0] = '\0';
        destination[0] = '\0';
        year = 0;
        month = 0;
        day = 0;
    }
    
    //keeping 2 parameter constructor for passenger
    Passenger::Passenger(const char* n, const char* d) {
        if (n != nullptr && d != nullptr) {
            strncpy(pass, n, sizeof(pass)-1);
            strncpy(destination, d, sizeof(destination)-1);
            year = 2018;
            month = 10;
            day = 01;
        }
        else {
            //setting Passenger to safe state if not valid
            *this = Passenger();
        }
    }
    
    Passenger::Passenger(const char* n, const char* dest, int y, int m, int d) {
        if (n != nullptr && dest != nullptr) {  //must have valid name in order to check date
            if (y >= 2018 && y <= 2020 && m >= 1 && m <= 12 && d >= 1 && d <= 31) { //checks for valid date
                strncpy(pass, n, sizeof(pass)-1);
                strncpy(destination, dest, sizeof(destination)-1);
                year = y;
                month = m;
                day = d;
            }
        }
        else {
            //setting Passenger to safe state if not valid
            *this = Passenger();
        }
    }
    
    bool Passenger::isEmpty () const {
        if (pass[0] != '\0' && destination[0] != '\0') {    //if name and destination are valid, it isnt empty
            return false;
        }
        return true;
    }
    
    void Passenger::display() const {
        if (isEmpty())
        {
            cout << "No passenger!" << endl;
        }
        else {
            cout << pass << " - " << destination << " on "
            << year << "/"
            << setfill('0') << setw(2) << month << "/"
            << setfill('0') << setw(2) << day << endl;
        }
    }
    
    const char* Passenger::name () const {
        return pass;
    }

    bool Passenger::canTravelWith(const Passenger& person) const {
        if (!strcmp(person.destination, this->destination) && this->year == person.year && this->month == person.month && this->day == person.day) { //checks destination, year, month, date to see if same
                return true;
            }
        return false;
    }
}

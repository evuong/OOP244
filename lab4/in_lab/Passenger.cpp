/**********************************************************
 // Workshop 4: Constructors
 // w4_in_lab.cpp
 // Edward Vuong 120246186
 // evuong1@myseneca.ca
 // Section G
 **********************************************************/

#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict {
    Passenger::Passenger() {
        name[0] = '\0';
        destination[0] = '\0';
    }
    
    Passenger::Passenger(const char* n, const char* d) {
        if (n != nullptr && d != nullptr) {
            strncpy(name, n, sizeof(name)-1);
            strncpy(destination, d, sizeof(destination)-1);
        }
        else {
            name[0] = '\0';
            destination[0] = '\0';
        }
    }
    
    bool Passenger::isEmpty () const {
        if (name[0] != '\0' && destination[0] != '\0') {
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
            cout << name << " - " << destination << endl;
        }
    }
}

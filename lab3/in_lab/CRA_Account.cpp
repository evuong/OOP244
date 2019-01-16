/**********************************************************
 // Workshop 3: Classes and Privacy
 // w3_in_lab.cpp
 // Edward Vuong 120246186
 // evuong1@myseneca.ca
 // Section G
 // This workshop demonstrates classes in C++ and
 // how member variables are defined privately, but
 // accessed through public member functions
 **********************************************************/

#include "CRA_Account.h"
#include <iostream>
#include <cstring>

using namespace std;



namespace sict {
    void CRA_Account::set (const char* familyName, const char* givenName, int sin) {
        if (sin > min_sin && sin < max_sin) {
            strncpy(fam_name, familyName, sizeof(fam_name));
            strncpy(given_name, givenName, sizeof(given_name));
            CRA_Account::sin = sin;
        }
    }
    
    bool CRA_Account::isEmpty() const {
        if (fam_name[1] == '\0' && given_name[1] == '\0' && sin == 0) {
            return true;
        }
        return false;
    }
    
    void CRA_Account::display() const {
        if (isEmpty()) {
            cout << "Account object is empty!" << endl;
        }
        else {
            cout << "Family Name : " << fam_name << endl;
            cout << "Given Name : " << given_name << endl;
            cout << "CRA Account : " << sin << endl;
        }
    }
    
}

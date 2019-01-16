/**********************************************************
 // Workshop 3: Classes and Privacy
 // w3_at_home.cpp
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
#include <iomanip>  //in order to use setprecision and fixed

using namespace std;

namespace sict {
    
    bool validateSin (int sin) {
        if (sin > min_sin && sin < max_sin) {
            int check = sin % 10;       //takes out the check number
            int array[8];               //new array to hold the number
            int count = 0;              //counter variable
            
            //convert rest of the sin number (except check number) to an array
            for (int i = 8; i >= 0; i--) {
                array[i] = sin % 10;
                sin /= 10;
            }
            
            int array2[4];      //another array to hold even digits
            
            //adding every second number onto itself and storing it into array2
            for (int i = 1; i < 8; i+=2) {
                array2[count] = array[i]*2;
                count++;
            }
            
            int sum = 0;    // variable for holding the totals
            
            //loop for adding every single digit to
            for (int i = 0; i < 4; i++){
                if (array2[i] > 10) {
                    sum += 1 + (array2[i] % 10);        //makes it 1 + whatever the second number is
                }
                else if (array2[i] == 10) {
                    sum++;
                }
                else if (array2[i] < 10) {
                    sum += array2[i];
                }
            }
            
            //adds the alternative numbers
            for (int i = 0; i < 7; i+=2) {
                sum += array[i];
            }
            
            //runs check to see that check number is matches the difference
            int next = 10 - (sum % 10);
            if (next == check) {
                return true;
            }
            else return false;
        }
        return false;
    }
    
    void CRA_Account::set (const char* familyName, const char* givenName, int sin) {
        
        //only sets if the sin is valid
        if (validateSin(sin)) {
            strncpy(fam_name, familyName, sizeof(fam_name));
            strncpy(given_name, givenName, sizeof(given_name));
            CRA_Account::sin = sin;
            CRA_Account::numYears = 0;
        }
    }
    
    bool CRA_Account::isEmpty() const {
        //if anything is empty, return result saying empty data
        if (fam_name[1] == '\0' || given_name[1] == '\0' || sin == 0) {
            return true;
        }
        return false;
    }
    
    void CRA_Account::display() const {
        if (isEmpty()) {
            cout << "Account object is empty!" << endl;
        }
        else {
            cout << "Family Name: " << fam_name << endl;
            cout << "Given Name : " << given_name << endl;
            cout << "CRA Account: " << sin << endl;
            }
        
            
        for (int i = 0; i < max_yrs; i++) {
            //prints out statement for balance if amount is over 2
            if (balance[i] > 2) {
                cout << fixed;
                cout << setprecision(2);
                cout << "Year (" << years[i] << ") balance owing: " << balance[i] << endl;
            }
            //prints out refund if balance if amount is less than -2
            else if (balance[i] < -2) {
                cout << fixed;
                cout << setprecision(2);
                cout << "Year (" << years[i] << ") refund due: " << balance[i]*-1 << endl;
            }
            //ignores the value if inbetween -2 and 2, saying nothing is due
            else {
                cout << "Year (" << years[i] << ") No balance owing or refund due!" << endl;
            }
        }
    }
    
    void CRA_Account::set (int year, double balance) {
        if (!isEmpty() && numYears < max_yrs) {
            years[numYears] = year;
            CRA_Account::balance[numYears] = balance;
            numYears++;
        }
    }
}

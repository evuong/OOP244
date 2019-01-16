// Workshop 6 - Class with a Resource
// Contact.cpp
// Edward Vuong
// November 1, 2018
//

#include "Contact.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

namespace sict{
    Contact::Contact() {
        name[0] = '\0';
        phone = nullptr;
        num = 0;
    }
    
    Contact::Contact(const char* name2, const long long* phone2, int num2) {
        if (name2 != nullptr && name2[0] != '\0') {
            strncpy(name, name2, sizeof(name)-1);
        }
        else {
            name[0] = '\0';
        }
        if (phone2 != nullptr && num2 > 0) {
            //creating new memory for phone
            phone = new long long[num2];
            num = num2;
            
            for (int i = 0; i < num2; i++) {
                phone[i] = phone2[i];
            }
        }
        
        else {
            phone = nullptr;
            num = 0;
        }
    }
    
    bool Contact::isEmpty() const {
        if (name[0] == '\0' && phone == nullptr && num == 0) {
            return true;
        }
        return false;
    }
    
    bool Contact::checkPhone(const long long phone2) const {
        string ph = to_string(phone2);
        //phone number cannot be less than 11 or greater than 12
        if (phone2 <= 0 || ph.length() < 11 || ph.length() > 12) {
            return false;
        }
        //phone number at position 7 from the end and 10 from the end cannot be 0
        if (ph[ph.length() - 7] == '0' || ph[ph.length() - 10] == '0') {
            return false;
        }
        return true;
    }
    
    void Contact::display() const {
        if (!isEmpty()) {
            cout << name << endl;
            for (int i = 0; i < num; i++) {
                string ph = to_string(phone[i]);
                if (ph.length() == 11) {
                    for (int i = 0; i < 11; i++) {
                        if (i == 0) {
                            cout << "(+";
                        }
                        if (i == 1) {
                            cout << ") ";
                        }
                        if (i == 4) {
                            cout << " ";
                        }
                        if (i == 7) {
                            cout << "-";
                        }
                        cout << ph[i];
                    }
                    cout << endl;
                }
                else if (ph.length() == 12) {
                    for (int i = 0; i < 12; i++) {
                        if (i == 0) {
                            cout << "(+";
                        }
                        if (i == 2) {
                            cout << ") ";
                        }
                        if (i == 5) {
                            cout << " ";
                        }
                        if (i == 8) {
                            cout << "-";
                        }
                        cout << ph[i];
                    }
                    cout << endl;
                }
            }
        }
        else {
            cout << "Empty contact!" << endl;
        }
    }
    
    Contact::~Contact() {
        //delete memory allocated for phone
        delete[] phone;
        phone = nullptr;
    }
}

// Workshop 6 - Class with a Resource
// Contact.h
// Edward Vuong
// November 1, 2018


// TODO: header file guard

#ifndef Contact_h
#define Contact_h
#include <stdio.h>

// TODO: create namespace
namespace sict{
    const int MAX_CHAR = 20;
    
    class Contact {
        char name [MAX_CHAR+1];
        long long* phone = nullptr;
        int num;
        
    public:
        Contact();
        Contact(const Contact&);
        Contact(const char*, const long long*, int);
        Contact& operator = (const Contact&);
        Contact& operator += (long long);
        ~Contact();
        bool isEmpty() const;
        bool checkPhone(const long long) const;
        void display() const;
    };
}

#endif

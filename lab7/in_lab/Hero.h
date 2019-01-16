// Workshop 7 - Derived Classes
// File w7_in_lab.cpp
// Version 2.0
// November 8, 2018
// Author       Edward Vuong
// Description
//       This file demonstrates the client module of w7
/////////////////////////////////////////////////////

#ifndef Hero_h
#define Hero_h

#include <stdio.h>
#include <iostream>

namespace sict {
    const int max_rounds = 100;
    class Hero {
        char name[41];
        int health;
        int attack;
    public:
        Hero();
        Hero (const char*, int, int);
        void operator-=(int);
        bool isAlive() const;
        int attackStrength();
        friend std::ostream& operator<<(std::ostream&, const Hero&);
        const char* display() const;
    };
    
    const Hero& operator* (const Hero& first, const Hero& second);
}

#endif

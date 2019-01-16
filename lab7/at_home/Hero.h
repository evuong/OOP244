// OOP244 Workshop 7 - Derived Classes
// w7_at_home.cpp
// Version 2.0
//  November 11, 2018
//  Edward Vuong
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
        int attackStrength() const;
        friend std::ostream& operator<<(std::ostream&, const Hero&);
        const char* display() const;
    };
    
    const Hero& operator* (const Hero& first, const Hero& second);
}

#endif

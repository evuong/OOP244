// OOP244 Workshop 7 - Derived Classes
// w7_at_home.cpp
// Version 2.0
//  November 11, 2018
//  Edward Vuong
/////////////////////////////////////////////////////

#ifndef SuperHero_h
#define SuperHero_h

#include <stdio.h>
#include <iostream>
#include "Hero.h"

namespace sict {
    
    //deriving from Hero class
    class SuperHero : public Hero {
        int bonus;
        int defense;
    public:
        SuperHero();
        SuperHero(const char*, int, int, int, int);
        int attackStrength() const;
        int defend() const;
    };
    const SuperHero& operator*(const SuperHero&, const SuperHero&);
}

#endif

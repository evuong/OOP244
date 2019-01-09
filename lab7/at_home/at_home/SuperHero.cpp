// OOP244 Workshop 7 - Derived Classes
// w7_at_home.cpp
// Version 2.0
//  November 11, 2018
//  Edward Vuong
/////////////////////////////////////////////////////

#include "SuperHero.h"
#include <cstring>
using namespace std;

namespace sict {
    
    //setting to safe empty state
    SuperHero::SuperHero() {
        bonus = 0;
        defense = 0;
    }
    
    //getting information from Hero
    SuperHero::SuperHero(const char* name, int health, int att, int att2, int def) : Hero (name, health, att) {
        bonus = att2;
        defense = def;
    }
    
    int SuperHero::attackStrength() const {
        return Hero::attackStrength() + bonus;
    }
    
    int SuperHero::defend() const {
        return defense;
    }
    
    //mostly same code from Hero.cpp, slightly modified to include extra attack and defense
    const SuperHero& operator* (const SuperHero& first, const SuperHero& second) {
        //making local copies of of the participants
        SuperHero one = first;
        SuperHero two = second;
        SuperHero winner;
        
        int rounds = 0;
        
        while (rounds < max_rounds && one.isAlive() && two.isAlive()) {
            one -= two.attackStrength() - one.defend();
            two -= one.attackStrength() - two.defend();
            rounds++;
        }
        
        winner = (!one.isAlive())&&(two.isAlive()) ? second : first;
        
        cout<< "Super Fight! " << one.display() << " vs " << two.display() << " : Winner is ";
        cout << winner << " in "  << rounds << " rounds." << endl;
        
        if (!one.isAlive() && two.isAlive()) {
            return second;
        }
        else {
            return first;
        }
    }
    
}

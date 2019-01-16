// OOP244 Workshop 7 - Derived Classes
// w7_at_home.cpp
// Version 2.0
//  November 11, 2018
//  Edward Vuong
/////////////////////////////////////////////////////

#include "Hero.h"
#include <cstring>
using namespace std;

namespace sict {
    
    //setting to safe empty state
    Hero::Hero () {
        name[0] = '\0';
        health = 0;
        attack = 0;
    }
    
    Hero::Hero(const char* heroName, int HP, int ad) {
        if (heroName != nullptr && heroName[0] != '\0') {
            strncpy(name, heroName, 40);
            health = HP;
            attack = ad;
        }
        else {
            *this = Hero();
        }
    }
    
    //subtracts the dmg from health if valid
    void Hero::operator -= (int dmg) {
        health -= dmg;
    }
    
    //checks if hero is alive or not
    bool Hero::isAlive() const {
        return health > 0;
    }
    
    //returns attack strength
    int Hero::attackStrength() const {
        if (attack > 0) {
            return attack;
        }
        return 0;
    }
    
    const char* Hero::display() const {
        return name;
    }
    
    //returns hero name if it is not null
    std::ostream& operator << (std::ostream& output, const Hero& hero) {
        if ((hero.name[0]) != '\0') {
            output << hero.name;
        }
        return output;
    }
    
    const Hero& operator* (const Hero& first, const Hero& second){
        //making local copies of of the participants
        Hero one = first;
        Hero two = second;
        Hero winner;
        
        int rounds = 0;
        
        while (rounds < max_rounds && one.isAlive() && two.isAlive()) {
            one -= two.attackStrength();
            two -= one.attackStrength();
            rounds++;
        }
        
        winner = (!one.isAlive())&&(two.isAlive()) ? second : first;
        
        cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
        cout << winner << " in "  << rounds << " rounds." << endl;
        
        if (!one.isAlive() && two.isAlive()) {
            return second;
        }
        else {
            return first;
        }
    }
    
}

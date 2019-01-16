/***********************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File Kingdom.h
 // Version 1.0
 // Date Sept 20, 2018
 // Author Edward Vuong
 // Description
 // Lab 2 - Dynamic Memory
 // OOP 244 - GG
 //
 // Revision History
 ///////////////////////////////////////////////////////////
 // Name     Date    Reason
 //
 ///////////////////////////////////////////////////////////
 ***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;

namespace sict {
    
    //defining display funciton to display kingdom name and population
    void display (const Kingdom& kd) {
        cout << kd.m_name << ", population " << kd.m_population << endl;
    }
}

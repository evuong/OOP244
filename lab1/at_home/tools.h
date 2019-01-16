/***********************************************************************
 // OOP244 Workshop 1: Compiling modular source code
 // File    w1_at_home.cpp
 // Version 1.0
 // Date        Sept 13, 2018
 // Author      Edward Vuong
 // Description 120246186
 // Email       evuong1@myseneca.ca
 // Course      OOP244 - SGG
 // This provides some source code in a single file to break
 // into modules and compile together
 //
 // Revision History
 // -----------------------------------------------------------
 // Name            Date            Reason
 // Edward Vuong    Sept 13, 2018
 /////////////////////////////////////////////////////////////////
 ***********************************************************************/

#ifndef namespace_tools_h
#define namespace_tools_h

#include <iostream>

using namespace std;

namespace sict {
    

// Performs a fool-proof integer entry
int getInt(int min, int max);
// Displays the user interface menu
int menu();
}

#endif /* tools_h */

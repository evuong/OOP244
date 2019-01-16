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

#ifndef namespace_Kingdom_h
#define namespace_Kingdom_h

namespace sict {
    
    struct Kingdom {
        char m_name [33];
        int m_population;
    };
    
    //declaring display function
    void display (const Kingdom&);

    //declaring overloaded display function
    void display (const Kingdom[], int);
}


#endif

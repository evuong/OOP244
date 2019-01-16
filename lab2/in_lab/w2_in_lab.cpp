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
using namespace sict;

void read(sict::Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
    
    Kingdom* pKingdom = nullptr;
    
    cout << "==========\n"
    << "Input data\n"
    << "==========\n"
    << "Enter the number of Kingdoms: ";
    cin >> count;
    cin.ignore();
    
    if (count < 1) return 1;
    
    //allocating memory
    pKingdom = new Kingdom [count];
    
    //collects each of the kingdom's name and population
    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
        cout << "Enter the name of the Kingdom: ";
        cin >> pKingdom[i].m_name;
        cout << "Enther the number of people living in " << pKingdom[i].m_name << ": ";
        cin >> pKingdom[i].m_population;
    }
    cout << "==========" << endl << endl;
    
    // testing that "display(...)" works
    cout << "------------------------------" << endl
    << "The 1st kingdom entered is" << endl
    << "------------------------------" << endl;
    sict::display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;
    
    //deallocating memory
    delete [] pKingdom;
    pKingdom = nullptr;
    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(sict::Kingdom& kingdom) {
    
    cout << "Enter the name of the Kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number of people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}

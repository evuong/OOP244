/***********************************************************************
 // OOP244 Workshop 1: Compiling modular source code
 // File    w1_in_lab.cpp
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

#include <iostream>
using namespace std;

#include "tools.h"
#include "graph.h"

// SeneGraph program
int main(){
    int noOfSamples = 0;
    int samples[MAX_NO_OF_SAMPLES] = { 0 };
    bool done = false;
    cout << "Welcome to SeneGraph" << endl;
    while (!done){
        cout << "No Of Samples: " << noOfSamples << endl;
        switch (menu()){
            case 1:
                cout << "Enter number of samples on hand: ";
                noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
                break;
            case 2:
                if (noOfSamples == 0){
                    cout << "First enter the number of Samples." << endl;
                }
                else{
                    cout << "Please enter the sample values: " << endl;
                    getSamples(samples, noOfSamples);
                }
                break;
            case 3:
                if (noOfSamples == 0){
                    cout << "First enter the number of Samples." << endl;
                }
                else if (samples[0] == 0){
                    cout << "Firt enter the samples." << endl;
                }
                else{
                    printGraph(samples, noOfSamples);
                }
                break;
            case 0:
                cout << "Thanks for using SeneGraph" << endl;
                done = true;
        }
    }
    return 0;
}

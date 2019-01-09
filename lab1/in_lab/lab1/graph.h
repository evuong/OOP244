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

#ifndef graph_hpp
#define graph_hpp

#include <iostream>
using namespace std;


#endif /* graph_hpp */

// Maximum number of samples in an graph
#define MAX_NO_OF_SAMPLES 20

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70.
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually
void printGraph(int samples[], int noOfSamples);

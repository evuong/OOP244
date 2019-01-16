/**********************************************************
 // Workshop 4: Overloading Operators
 // w5_in_lab.cpp
 // Edward Vuong 120246186
 // evuong1@myseneca.ca
 // Section G
 **********************************************************/


#ifndef Fraction_h
#define Fraction_h

#include <stdio.h>

namespace sict{

    class Fraction {
    private:
        int num;  //numerator
        int den;  //denominator
        
        int max() const;
        int min() const;
        void reduce ();
        int gcd () const;
    public:
        Fraction ();
        Fraction (int, int);
        bool isEmpty () const;
        void display() const;
        Fraction operator+(const Fraction&) const;
    
    };

}


#endif

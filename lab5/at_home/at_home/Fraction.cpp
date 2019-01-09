/**********************************************************
 // Workshop 4: Overloading Operators
 // w5_in_lab.cpp
 // Edward Vuong 120246186
 // evuong1@myseneca.ca
 // Section G
 **********************************************************/

#include <iostream>
#include "Fraction.h"

using namespace std;
namespace sict{
    Fraction::Fraction() {
        num = 0;
        den = 0;
    }
    
    Fraction::Fraction (int numerator, int denominator) {
        if (numerator >= 0 && denominator >= 0) {
            num = numerator;
            den = denominator;
            reduce();       //reducing after numerator and denominator are set
        }
        else {
            *this = Fraction();     //setting to safe state
        }
    }
    
    int Fraction::max() const {
        if (num > den) {
            return num;
        }
        return den;
    }
    
    int Fraction::min() const {
        if (num > den) {
            return den;
        }
        return num;
    }
    
    void Fraction::reduce () {
        int divident = gcd();   //divident captures the gcd
        num /= divident;
        den /= divident;
    }
    
    //CODE IS GIVEN
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;
        
        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }
    
    bool Fraction::isEmpty () const {
        if (num != 0 && den != 0) {
            return false;
        }
        return true;
    }
    
    void Fraction::display() const {
        if (isEmpty()) {
            cout << "no fraction stored";
        }
        else if (!isEmpty() && den == 1) {      //if denominator is equal to 0, returns just numerator
            cout << num;
        }
        else {
            cout << num << "/" << den;
        }

    }
    
    Fraction Fraction::operator+(const Fraction& rhs) const {
        Fraction sum;
        if (!isEmpty() && !rhs.isEmpty()) {
            sum.num = (this->num * rhs.den) + (this->den * rhs.num);    //ad + bc
            sum.den = this->den * rhs.den;                              //bd
            return sum;
        }
        sum = Fraction();
        return sum;
    }
    
    Fraction Fraction::operator * (const Fraction& rhs) const {
        Fraction multiple;
        if (!isEmpty() && !rhs.isEmpty()) {
            multiple.num = this->num * rhs.num;
            multiple.den = this->den * rhs.den;
            return multiple;
        }
        multiple = Fraction();
        return multiple;
    }
    
    bool Fraction::operator == (const Fraction& rhs) const {
        if (!isEmpty() && !rhs.isEmpty()) {
            if (this->num == rhs.num && this->den == rhs.den) {
                return true;
            }
            return false;
        }
            return false;
    }
    
    bool Fraction::operator != (const Fraction& rhs) const {
        if (*this == rhs) {
            return true;
        }
        return false;
    }
    
    Fraction& Fraction::operator += (const Fraction& rhs) {
        *this = *this + rhs;
        reduce();
        return *this;
    }
}


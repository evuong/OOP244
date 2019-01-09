/////////////////////////////////////////////////////////////////
// Final Project - Milestone 5
// November 28, 2018
// Edward Vuong
// 120246186
/////////////////////////////////////////////////////////////////

#ifndef Good_h
#define Good_h

#include <iostream>
#include "Error.h"
#include "iGood.h"

namespace aid {
    //PREDEFINED CONSTANTS
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double tax_rate = 0.13;
    
    class Good : public iGood {
        char good_type;
        char good_sku[max_sku_length + 1];
        char good_unit[max_unit_length + 1];
        char* good_name;
        int on_hand;
        int amount_needed;
        double price_notax;
        bool taxable;
    protected:
        Error state;
        void name (const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double itemPrice() const;
        double itemCost() const;
        void message(const char*);
        bool isClear() const;
    public:
        Good (char='N');
        Good (const char*, const char*, const char*, int=0, bool=true, double=0, int=0);
        Good (const Good&);
        Good& operator=(const Good&);
        ~Good();
        std::fstream& store (std::fstream& file, bool newLine=true) const;
        std::fstream& load (std::fstream& file);
        std::ostream& write (std::ostream& os, bool linear) const;
        std::istream& read (std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const iGood&) const;
        int operator+=(int);
    };
    double operator+=(double&, const iGood&);
    std::ostream& operator<<(std::ostream&, const iGood&);
    std::istream& operator>>(std::istream&, iGood&);
}

#endif

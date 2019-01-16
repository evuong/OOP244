/////////////////////////////////////////////////////////////////
// Final Project - Milestone 5
// November 28, 2018
// Edward Vuong
// 120246186
/////////////////////////////////////////////////////////////////

#include "Good.h"
#include <iostream>
#include <cstring>
#include <memory>
#include <fstream>
#include <iomanip>

using namespace std;

namespace aid {
    void Good::name (const char* name) {
        if (name != nullptr) {
            good_name = new char [strlen(name)];
            strncpy(good_name, name, sizeof(good_name)-1);
        }
        else {
            good_name = nullptr;
        }
    }
    
    const char* Good::name() const {
        if (good_name != nullptr) {
            return good_name;
        }
        else {
            return nullptr;
        }
    }
    
    const char* Good::sku() const {
        return good_sku;
    }
    
    const char* Good::unit() const {
        return good_unit;
    }
    
    bool Good::taxed() const {
        return taxable;
    }
    
    double Good::itemPrice() const {
        return price_notax;
    }
    
    //if item is taxable, return price before tax times tax rate otherwise return price before tax
    double Good::itemCost() const {
        if (taxable) {
            return price_notax * (1 + tax_rate);
        }
        return price_notax;
    }
    
    //using the Error's message function
    void Good::message(const char* msg) {
        state.message(msg);
    }
    
    //return what the Error isClear function returns
    bool Good::isClear() const {
        return state.isClear();
    }
    
    //safe empty state
    Good::Good(char type) {
        good_type = type;
        good_sku[0] = '\0';
        good_unit[0] = '\0';
        good_name = nullptr;
        on_hand = 0;
        amount_needed = 0;
        price_notax = 0;
        taxable = false;
    }
    
    Good::Good(const char* sku, const char* itemname, const char* unit, int num, bool if_tax, double pbt, int needed) {
        strncpy(good_sku, sku, sizeof(good_sku)-1);
        name(itemname);
        strncpy(good_unit, unit, sizeof(good_unit)-1);
        
        on_hand = num;
        taxable = if_tax;
        price_notax = pbt;
        amount_needed = needed;
    }
    
    Good::Good(const Good& copy) {
        good_name = nullptr;
        *this = copy;
    }
    
    Good& Good::operator=(const Good& copy) {
        if (this != &copy) {
            good_type = copy.good_type;
            strncpy(good_sku, copy.good_sku, sizeof(good_sku)-1);
            strncpy(good_unit, copy.good_unit, sizeof(good_unit)-1);
            on_hand = copy.on_hand;
            amount_needed = copy.amount_needed;
            price_notax = copy.price_notax;
            taxable = copy.taxable;
            
            delete[] good_name;
            name(copy.good_name);
        }
        return *this;
    }
    
    Good::~Good() {
        delete[] good_name;
    }
    
    std::fstream& Good::store(std::fstream& file, bool newLine) const {
        file << good_type << ',' << good_sku << ',' << good_name << ',' << good_unit << ',' << taxable << ',' << price_notax << ',' << on_hand << ',' << amount_needed;
        
        if (newLine) {
            file << endl;
        }
        return file;
    }
    
    std::fstream& Good::load(std::fstream& file) {
        char sku2[max_sku_length];
        char name2[max_name_length];
        char unit2[max_unit_length];
        char taxchar;
        bool taxstatus = false;
        int onhand2;
        int needed2;
        double price_notax2;
        
        if (file.is_open()) {
            file.getline(sku2, max_sku_length, ',');
            file.getline(name2, max_name_length, ',');
            file.getline(unit2, max_unit_length, ',');
            
            file >> taxchar;
            if (taxchar == '1') {
                taxstatus = true;
            }
            else if (taxchar == '0') {
                taxstatus = false;
            }
            
            file.ignore();
            file >> price_notax2;
            file.ignore();
            file >> onhand2;
            file.ignore();
            file >> needed2;
            file.ignore();
            
            *this = Good(sku2, name2, unit2, onhand2, taxstatus, price_notax2, needed2);
        }
        return file;
    }
    
    std::ostream& Good::write(std::ostream& os, bool linear) const {
        if (state.isClear()) {
            if (linear) {
                os << setw(max_sku_length) << left << sku() << '|'
                << setw(20) << left << name() << '|'
                << setw(7) << fixed << setprecision(2) << right << itemCost() << '|'
                << setw(4) << right << quantity() << '|'
                << setw(10) << left << unit() << '|'
                << setw(4) << right << qtyNeeded() << '|';
            }
            else {
                os << " Sku: " << sku() << endl;
                os << " Name (no spaces): " << name() << endl;
                os << " Price: " << itemPrice() << endl;
                
                if (taxed()) {
                    os << " Price after tax: " << itemCost() << endl;
                }
                else {
                    os << " Price after tax:  N/A" << endl;
                }
                
                os << " Quantity on Hand: " << quantity() << " " << unit() << endl;
                os << " Quantity needed: " << qtyNeeded();
            }
        }
        else {
            os << state.message();
        }
        return os;
    }
    
    std::istream& Good::read(std::istream& is) {
        is.clear();
        char tax;
        
        good_name = new char[max_name_length+1];

        cout << " Sku: ";
        is >> good_sku;
        
        cout << " Name (no spaces): ";
        is >> good_name;
        
        cout << " Unit: ";
        is >> good_unit;
        
        cout << " Taxed? (y/n): ";
        is >> tax;
        if (tax == 'Y' || tax == 'y') {
            taxable = true;
        }
        else if (tax == 'N' || tax == 'n') {
            taxable = false;
        }
        else {
            state.message("Only (Y)es or (N)o are acceptable");
            is.setstate(ios::failbit);
            return is;
        }
        
        //checking for price
        if (!is.fail()) {
            cout << " Price: ";
            is >> price_notax;
            if (is.fail()) {
                state.message("Invalid Price Entry");
                return is;
            }
        }
        
        //checking for quantity
        if (!is.fail()) {
            cout << " Quantity on hand: ";
            is >> on_hand;
            if (is.fail()) {
                state.message("Invalid Quantity Entry");
                return is;
            }
        }
        
        //checking for amount neeeded
        if (!is.fail()) {
            cout << " Quantity needed: ";
            is >> amount_needed;
            if (is.fail()) {
                state.message("Invalid Quantity Needed Entry");
                return is;
            }
        }
        
        if (!is.fail()) {
            state.message("");
        }
        is.ignore();
        return is;
    }
    
    bool Good::operator==(const char* sku) const {
        return strcmp(good_sku, sku) == 0;
    }
    
    double Good::total_cost() const {
        return itemCost()*quantity();
    }
    
    void Good::quantity(int num) {
        if (num > 0) {
            on_hand = num;
        }
    }
    
    bool Good::isEmpty() const {
        return good_name == nullptr;
    }
    
    int Good::qtyNeeded() const {
        return amount_needed;
    }
    
    int Good::quantity() const{
        return on_hand;
    }
    
    bool Good::operator>(const char* sku) const {
        return strcmp(good_sku, sku) > 0;
    }
    
    bool Good::operator>(const iGood& copy) const {
        return strcmp(good_name, copy.name()) > 0;
    }
    
    int Good::operator+=(int add) {
        if (add > 0) {
            return on_hand += add;
        }
        return on_hand;
    }
    
    std::ostream& operator<<(std::ostream& os, const iGood& current) {
        return current.write(os, true);
    }
    
    std::istream& operator>>(std::istream& is, iGood& current) {
        current.read(is);
        return is;
    }
    
    double operator+=(double& add, const iGood& current) {
        return add + current.total_cost();
    }
}

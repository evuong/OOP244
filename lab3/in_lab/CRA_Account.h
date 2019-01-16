/**********************************************************
 // Workshop 3: Classes and Privacy
 // w3_in_lab.cpp
 // Edward Vuong 120246186
 // evuong1@myseneca.ca
 // Section G
 // This workshop demonstrates classes in C++ and
 // how member variables are defined privately, but
 // accessed through public member functions
 **********************************************************/

#ifndef namespace_CRA_Account_h
#define namespace_CRA_Account_h

namespace sict {
    const int max_name_length = 41;
    const int min_sin = 100000000;
    const int max_sin = 999999999;
    
    class CRA_Account {
        char fam_name [max_name_length];
        char given_name [max_name_length];
        int sin;
    public:
        void set(const char* familyName, const char* givenName, int sin);
        bool isEmpty() const;
        void display() const;
    };
    
}

#endif

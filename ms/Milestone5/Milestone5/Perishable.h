//
// Name: Huy Lam
// Section: GG
// Date: 27/11/2018
//


#ifndef PERISHABLE_H
#define PERISHABLE_H

#include <iostream>
#include "Good.h"
#include "Date.h"

namespace aid {
    
    class Perishable : public Good {
        Date exp;
    public:
        Perishable();
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        const Date& expiry() const;
    };
}

#endif

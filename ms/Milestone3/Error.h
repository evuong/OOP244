// Final Project Milestone 2 - Error Class
// Version 3.4
// Date    November 9, 2018
// Author  Edward Vuong
//
/////////////////////////////////////////////////////////////////

#ifndef Error_h
#define Error_h

#include <stdio.h>
#include <iostream>

namespace aid {
    class Error {
        char* msg;
    public:
        explicit Error (const char* errorMessage = nullptr);
        Error (const Error& em) = delete;
        Error& operator=(const Error& em) = delete;
        virtual ~Error();
        void clear();
        bool isClear() const;
        void message (const char* str);
        const char* message() const;
    };
    std::ostream& operator<<(std::ostream&, const Error&);
}
#endif


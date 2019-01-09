/////////////////////////////////////////////////////////////////
// Final Project - Milestone 5
// November 28, 2018
// Edward Vuong
// 120246186
/////////////////////////////////////////////////////////////////

#ifndef Error_h
#define Error_h

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

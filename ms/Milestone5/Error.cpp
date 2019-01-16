/////////////////////////////////////////////////////////////////
// Final Project - Milestone 5
// November 28, 2018
// Edward Vuong
// 120246186
/////////////////////////////////////////////////////////////////


#include "Error.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace aid {
    //default error message handler (if empty set it to safe, if not allocate new memory for message)
    Error::Error(const char* errorMessage) {
        if (errorMessage == nullptr) {
            msg = new char[1];
            msg[0] = '\0';
        }
        else {
            msg = new char [strlen(errorMessage)+1];
            strcpy(msg, errorMessage);
        }
    }
    
    //destructor deleting allocated memory for error
    Error::~Error() {
        delete[] msg;
        msg = nullptr;
    }
    
    //clearing the error message
    void Error::clear() {
        msg = nullptr;
    }
    
    //checking if mesg is clear or not and returning true/false
    bool Error::isClear() const {
        return msg == nullptr || msg[0] == '\0';
    }
    
    //deallocate previous memory, makes new memory and copies errorMessage into msg
    void Error::message (const char* str) {
        if (str != nullptr || str[0] != '\0') {
            delete[] msg;
            msg = new char[strlen(str)+1];
            strncpy(msg, str, strlen(str)+1);
        }
        else {
            this->clear();
        }
    }
    
    //returns the msg
    const char* Error::message() const {
        return msg;
    }
    
    //checks if error object is clear and if not, outputs the error message
    std::ostream & operator<<(std::ostream & output, const Error& em) {
        if (!em.isClear()) {
            output << em.message();
        }
        return output;
    }
    
}


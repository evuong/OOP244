// Final Project Milestone 2 - Error Class
// Version 3.4
// Date    November 9, 2018
// Author  Edward Vuong
//
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
            int size = strlen(errorMessage);
            msg = new char [size+1];
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
        msg[0] = '\0';
    }
    
    //checking if mesg is clear or not and returning true/false
    bool Error::isClear() const {
        return msg == nullptr || msg[0] == '\0';
    }
    
    //deallocate previous memory, makes new memory and copies errorMessage into msg
    void Error::message (const char* errorMessage) {
        delete[] msg;
        int size = strlen(errorMessage);
        msg = new char [size+1];
        strcpy(msg, errorMessage);
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


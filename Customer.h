#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer: public User {
    public:
        //constructor
        Customer(const string& name = "Unknown", const int rating = 0, const Location& location = Location(0, 0));
        
        //functions
        void print() const;

    private:
        static const char code;
        static int nextId;
};
#endif
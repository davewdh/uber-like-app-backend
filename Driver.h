#ifndef DRIVER_H
#define DRIVER_H

#include "defs.h"
#include "User.h"

class Driver: public User {
    public:
        //constructor 
        Driver(const string& name = "Unknown", const int rating = 0, const Size& size = small, const Location& location = Location(0,0));
        
        //functions
        const int getDistance(const Location& location);
        bool match(const int rating, const Size& size) const;
        void print() const;

    private:
        Size size;
        static const char code;
        static int nextId;
};
#endif
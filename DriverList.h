#ifndef DRIVERLIST_H
#define DRIVERLIST_H
#include <string>

#include "Driver.h"

class DriverList{

    class Node {

        public:
            Driver* data;
            Node*   next;
    };

    public:
        //constructor
        DriverList();
        
        //destructor
        ~DriverList();

        //functions
        void add(Driver* driver);
        bool get(const string& name, Driver** driver) const;
        bool remove(const string& name, Driver** driver);
        bool findRide(const int rating, const Size& size, const Location& location, Driver** driver) const;
        bool isEmpty() const;
        void print() const;  
        void clear();

    private:
        Node* head;

};


#endif


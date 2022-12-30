#ifndef COVOITURE_H
#define COVOITURE_H

#include "Driverlist.h"
#include "CustomerList.h"

class CoVoiture {
    public:
        //constructor
        CoVoiture();

        //destructor
        ~CoVoiture();

        //functions
        void addDriver(const string& name, const int rating, const Size size, const Location& location);
        bool getDriver(const string& name, Driver** driver) const;
        bool removeDriver(const string& name);
        void addCustomer(const string& name, const int rating, const Location& location);
        bool getCustomer(const string& name, Customer** customer) const;
        bool removeCustomer(const string& name);
        bool findRide(const string& name, const Size& size, Driver** driver) const;
        void printDrivers() const;
        void printCustomers() const;

    private:
        DriverList drivers;
        CustomerList customers;
};
#endif
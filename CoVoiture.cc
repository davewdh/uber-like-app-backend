#include "CoVoiture.h"

//constructor
CoVoiture::CoVoiture() {
}

//destructor (delete all Drivers and Customers)
CoVoiture::~CoVoiture() {
    drivers.clear();
    customers.clear();
}

//add a new Driver with the given parameters.
void CoVoiture::addDriver(const string& name, const int rating, const Size size, const Location& location) {
    drivers.add(new Driver(name, rating, size, location));
}

//find and return a Driver with the given name and return true. Return false if no such Driver exists
bool CoVoiture::getDriver(const string& name, Driver** driver) const {
    if (!drivers.get(name, driver)) {
        cout << "Cannot find the driver with the given name!" << endl;
        return false;
    }
    return true;
}

//if a Driver with the name exists, delete the Driver and return true. Otherwise return false.
bool CoVoiture::removeDriver(const string& name) {
    Driver* driver;
    if (drivers.remove(name, &driver)) {
        delete driver;
        return true;
    }
    cout << "Remove failed! Cannot find the driver with the given name!" << endl;
    return false;
}

//add a new Customer with the given parameters
void CoVoiture::addCustomer(const string& name, const int rating, const Location& location) {
    customers.add(new Customer(name, rating, location));
}

//find and return a Customer with the given name and return true. Return false if no such Customer exists.
bool CoVoiture::getCustomer(const string& name, Customer** customer) const {
    if (!customers.get(name, customer)) {
        cout << "Cannot find the customer with the given name!" << endl;
        return false;
    }
    return true;
}

//if a Customer with the name exists, delete the Customer and return true. Otherwise return false
bool CoVoiture::removeCustomer(const string& name) {
    Customer* customer;
    if (customers.remove(name, &customer)) {
        delete customer;
        return true;
    }
    cout << "Remove failed! Cannot find the customer with the given name!" << endl;
    return false;
}

//find a Customer with the given name. If such a Customer does not exist, return false. 
//Then find the closest Driver that matches the given Size and the rating of the Customer. If no Driver matches, return false.
bool CoVoiture::findRide(const string& name, const Size& size, Driver** driver) const {
    Customer* customer;
    if (!customers.get(name, &customer)) {
        cout << "Cannot find the customer with the given name!" << endl;
        return false;
    }
    if (!drivers.findRide(customer->getRating(), size, customer->getLocation(), driver)) {
        cout << "Cannot find the closest Driver that matches the given Size and the rating of the Customer." << endl;
        return false;
    }
    return true;
}

void CoVoiture::printDrivers() const {
    drivers.print();
}

void CoVoiture::printCustomers() const {
    customers.print();
}
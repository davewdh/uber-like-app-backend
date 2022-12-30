#include "Customer.h"

int Customer::nextId = 1;
const char Customer::code = 'C';

//constructor
Customer::Customer(const string& name, const int rating, const Location& location) : User(code, nextId++, name, rating, location) {

}
        
void Customer::print() const {
    User::print();
}
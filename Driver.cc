#include "Driver.h"

int Driver::nextId = 1;
const char Driver::code = 'D';

//constructor
Driver::Driver(const string& name, const int rating, const Size& size, const Location& location) : User(code, nextId++, name, rating, location), size(size) {
}

//return the distance from the Driver’s Location to another Location (which should be passed in as a parameter).
const int Driver::getDistance(const Location& location) {
    return currentLocation.getDistance(location);
}

//Return true if the Size member variable is at least as big as the Size parameter
//and the difference between the Driver rating and the rating parameter is at most 2
bool Driver::match(const int rating, const Size& size) const {
    return (this->size >= size && abs(this->rating - rating) <= 2);
}

void Driver::print() const {
    User::print();
    cout << "Size: " << this->size << endl;
}
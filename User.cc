#include "User.h"

//constructor
User::User(const char code, const int id, const string& name, const int rating, const Location& location) {
    this->id = code + to_string(id);
    this->name = name;
    this->rating = rating;
    setLocation(location);
}

//getters
const string& User::getName() const {
    return this->name;
}

const string& User::getId() const {
    return this->id;
}

const int User::getRating() const {
    return this->rating;
}

const Location& User::getLocation() const {
    return currentLocation;
}

//setters
void User::setRating(const int rating) {
    this->rating = rating;
}

void User::setLocation(const int x, const int y) {
    currentLocation.setLocation(x, y);
}

void User::setLocation(const Location& location) {
    currentLocation.setLocation(location.x, location.y);
}

//returns true if this User comes before the User paramater in alphabetical order
bool User::lessThan(const User& user) const {
    return this->name < user.name;
}

void User::print() const {
    cout << "ID: " << this->id << ". Name: " << this->name << ". Rating: " << this->rating << ". Location: ";
    currentLocation.print();
    cout << endl;
}
#ifndef USER_H
#define USER_H

#include "Location.h"

class User {
    public:
        //constructor
        User(const char code, const int id, const string& name, const int rating, const Location& location);

        //getters
        const string& getName() const;
        const string& getId() const;
        const int getRating() const;
        const Location& getLocation() const;

        //setters
        void setRating(const int rating);
        void setLocation(const int x, const int y);
        void setLocation(const Location& location);

        //functions
        bool lessThan(const User& user) const;
        void print() const;

    protected:
        string id;
        string name;
        int rating;
        Location currentLocation;       
};
#endif
#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <string>

#include "Customer.h"

class CustomerList{

    class Node {

        public:
            Customer* data;
            Node*   next;
    };

    public:
        //constructor
        CustomerList();
        
        //destructor
        ~CustomerList();

        //functions
        void add(Customer* customer);
        bool get(const string& name, Customer** customer) const;
        bool remove(const string& name, Customer** customer);
        bool isEmpty() const;
        void print() const;  
        void clear();

    private:
        Node* head;
};
#endif


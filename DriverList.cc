#include <iostream>
#include <string>
using namespace std;

#include "DriverList.h"

//constructor
DriverList::DriverList(): head(NULL){}

//destructor (delete all Nodes)
DriverList::~DriverList(){
    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode;
    }

}

//add in sorted order by name
void DriverList::add(Driver* driver){
    Node* newNode = new Node();
    newNode->data = driver;
    newNode->next = NULL;

    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        if (newNode->data->lessThan(*currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == NULL){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;

}

//return false if name not found
bool DriverList::get(const string& name, Driver** driver) const{
    Node * currNode = head;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *driver = NULL;
        return false;
    }
    //currNode is not NULL
    *driver = currNode->data;
    return true;
}

bool DriverList::remove(const string& name, Driver** driver){
    Node * currNode = head;
    Node * prevNode = NULL;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *driver = NULL;
        return false;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *driver = currNode->data;
    delete currNode;
    return true;
}

//Find the closest Driver to the Location parameter that matches the given Size and rating. 
//If no Driver matches the parameters, return false,
bool DriverList::findRide(const int rating, const Size& size, const Location& location, Driver** driver) const {
    Node * currNode = head;

    while (currNode!=NULL){
        if (currNode->data->match(rating, size)){
            *driver = currNode->data;
            break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *driver = NULL;
        return false;
    }

    while (currNode!=NULL){
        if (currNode->data->match(rating, size)) {
            if (currNode->data->getDistance(location) < (**driver).getDistance(location)){
                *driver = currNode->data;
            }
        }
        currNode = currNode->next;
    }
    //currNode is not NULL
    return true;
}

void DriverList::print() const{
    if (isEmpty()) {
        cout <<"List empty"<<endl;
        return;
    }
    
    Node* currNode = head;
    cout<<"Print list..."<<endl;

    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}

//delete all data (and Nodes)
void DriverList::clear() {
    if (isEmpty()) {
        return;
    }
    Node * currNode = head;
    Node * prevNode = NULL;

    while (currNode!=NULL){
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode->data;
        delete prevNode;
    }
    head = currNode;
}

bool DriverList::isEmpty() const{
    return head == NULL;
}
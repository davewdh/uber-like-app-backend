#include <iostream>
#include <string>
using namespace std;

#include "CustomerList.h"

//constructor
CustomerList::CustomerList(): head(NULL){}

//destructor (delete all Nodes)
CustomerList::~CustomerList(){
    Node* currNode = head;
    Node* prevNode = NULL;

    while(currNode!=NULL){
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode;
    }

}

//add in sorted order by name
void CustomerList::add(Customer* customer){
    Node* newNode = new Node();
    newNode->data = customer;
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
bool CustomerList::get(const string& name, Customer** customer) const{
    Node * currNode = head;

    while (currNode!=NULL){
        if (currNode->data->getName() == name){
           break; 
        }
        currNode = currNode->next;
    }

    if (currNode == NULL){
        *customer = NULL;
        return false;
    }
    //currNode is not NULL
    *customer = currNode->data;
    return true;
}

bool CustomerList::remove(const string& name, Customer** customer){
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
        *customer = NULL;
        return false;
    }
    //currNode is not NULL
    if (prevNode == NULL){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    *customer = currNode->data;
    delete currNode;
    return true;
}

void CustomerList::print() const{
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
void CustomerList::clear() {
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

bool CustomerList::isEmpty() const{
    return head == NULL;
}
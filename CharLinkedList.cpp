/*
 *  CharLinkedList.cpp
 *  Sandra Ortellado
 *  9/26/22
 *
 *  CS 15 HW 2
 *
 *  Purpose: Define all member functions of the CharLinkedList class
 *
 */
#include <iostream>
#include "CharLinkedList.h"

using namespace std;

//Default constructor takes no parameters and initializes an empty list
CharLinkedList::CharLinkedList() {
    front = nullptr;
    tail = nullptr;
    count  = 0;
}

//Second constructor takes in a single character as a parameter
//and creates a one element list consisting of that character
CharLinkedList::CharLinkedList(char c) {
    Node *newnode = new Node;
    newnode->info = c;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    front = newnode;
    tail = newnode;
    count = 1;
}

//Third constructor takes an array of characters and the integer
//length of that array of characters as parameters. It will create a
//list containing the characters in the array
CharLinkedList::CharLinkedList(char *arr, int arr_size) {
    if (arr_size == 0) {
        front = nullptr;
        tail = nullptr;
        count = 0;
        return;
    }

    char val = arr[0];
    Node *curr = new Node;
    curr->info = val;
    curr->prev = nullptr;
    front = curr;

    for (int i = 1; i < arr_size - 1; i++) {
        Node *next = new Node;
        next->info = arr[i];
        next->prev = curr;
        curr->next = next;
        curr = next;
    }

    char last = arr[arr_size - 1];
    Node *end = new Node;
    end->info = last;
    end->prev = curr;
    curr->next = end;
    end->next = nullptr;
    tail = end;
    count = arr_size;
}

//A copy constructor for the class that makes a deep copy of a given instance
CharLinkedList::CharLinkedList(const CharLinkedList &other) {
    Node *curr = other.front;
    front = new Node;
    Node *newcurr = front;
    Node *prev = nullptr;

    while (curr->next) {
        newcurr->info = curr->info;
        curr = curr->next;
        Node *next = new Node;
        newcurr->next = next;
        next->prev = newcurr;
        prev = newcurr;
        newcurr = newcurr->next;
    }
    
    newcurr->info = curr->info;
    newcurr->next = nullptr;
    newcurr->prev = prev;
    tail = newcurr;
    tail->next = nullptr;

    count = other.count;

}

/* assignment operator
 * Purpose: Recycles the storage
  associated with the instance on the left of the assignment and 
  makes a deep copy of the instance on the right hand side 
  into the instance on the left hand side
 * Parameters: memory address of CharLinkedList instance
 * Returns: nothing
 */
void CharLinkedList::operator=(const CharLinkedList &other) {

    while (front) {
        this->popFromBack();
    }

    Node *curr = other.front;

    front = new Node;
    Node *newcurr = front;
    Node *prev = nullptr;

    while (curr->next) {
        newcurr->info = curr->info;
        curr = curr->next;
        Node *next = new Node;
        newcurr->next = next;
        next->prev = newcurr;
        prev = newcurr;
        newcurr = newcurr->next;
    }
    
    newcurr->info = curr->info;
    newcurr->next = nullptr;
    newcurr->prev = prev;
    tail = newcurr;
    tail->next = nullptr;

    count = other.count;
}

//Destructor that destroys/deletes/recycles all heap-allocated data 
//in the current list
CharLinkedList::~CharLinkedList() {

    if (!front) {
        front = nullptr;
        tail = nullptr;
        return;
    }

    Node *curr = front;
 
    for (int i = 0; i < count - 1; i++) {
        Node *next = curr->next;
        curr->next = nullptr;
        curr->prev = nullptr;
        delete curr;
        next->prev = nullptr;
        curr = next;
    }

    if (curr) {
        curr->prev = nullptr;
        curr->next = nullptr;
        delete curr;
    }
    front = nullptr;
    tail = nullptr;
}

/* isEmpty
 * Purpose: Determine if this specific instance of the class is empty
 * Parameters: none
 * Returns: boolean true or false
 */
bool CharLinkedList::isEmpty() {
    if (count == 0) {
        return true;
    }
    return false;
}

/* clear
 * Purpose: Makes the instance into an empty linked list
 * Parameters: none
 * Returns: nothing
 */
void CharLinkedList::clear() {
    Node *curr = front;

    for (int i = 0; i < count - 1; i++) {
        Node *next = curr->next;
        curr->next = nullptr;
        curr->prev = nullptr;
        delete curr;
        next->prev = nullptr;
        curr = next;
    }

   if (curr) {
        curr->prev = nullptr;
        curr->next = nullptr;
        delete curr;
    }

    front = nullptr;
    tail = nullptr;
    count = 0;
}

/* size
 * Purpose: Determines the number of characters in the linked list
 * Parameters: none
 * Returns: an integer value that is the number of characters in the linked list
 */
int CharLinkedList::size() {
    return count;
}

/* first
 * Purpose: Fetch the first element (char) in the linked list
 * Parameters: none
 * Returns: the first element (char) in the linked list
 */
char CharLinkedList::first() {
    if (this->isEmpty()) {
        throw runtime_error("cannot get first of empty LinkedList");
    }
    return front->info;
}

/* last
 * Purpose: Fetch the first element (char) in the linked list
 * Parameters: none
 * Returns: the first element (char) in the linked list
 */
char CharLinkedList::last() {
    if (this->isEmpty()) {
        throw runtime_error("cannot get last of empty LinkedList");
    }
    return tail->info;
}

/* elementAt
 * Purpose: Gives the char in the linked list at a given index
 * Parameters: integer index
 * Returns: char in the linked list at that index
 */
char CharLinkedList::elementAt(int index) {
    if (index < 0 || index >= count) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(count) + ")");
    }
    Node *curr = front;

    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    return curr->info;
}

/* print
 * Purpose: Makes a string out of the chars in the linked list
 * Parameters: none
 * Returns: a string which contains the characters of the CharLinkedList
 */void CharLinkedList::print() {
    if (this->isEmpty()) {
        cout << "[CharLinkedList of size 0 <<>>]" << endl;
        return;
    }
    string stringed = "";
    Node *curr = front;
    while (curr) {
        stringed += curr->info;
        curr = curr->next;
    } 
    cout << "[CharLinkedList of size " + to_string(count) + " <<" + stringed + ">>]" << endl;
}

/* pushAtBack
 * Purpose: Inserts given new char at the end of the existing chars
 * Parameters: an element (char)
 * Returns: nothing
 */
void CharLinkedList::pushAtBack(char c) {
    if (this->isEmpty()) {
        Node *curr = new Node;
        curr->info = c;
        curr->prev = nullptr;
        curr->next = nullptr;
        count++;
        tail = curr;
        front = curr;
    } else {
        Node *curr = new Node;
        curr->info = c;
        curr->prev = tail;
        tail->next = curr;
        curr->next = nullptr;
        count++;
        tail = curr;
    }
}

/* pushAtFront
 * Purpose: Inserts given new char at the front of existing char linked list
 * Parameters: an element (char)
 * Returns: nothing
 */
void CharLinkedList::pushAtFront(char c) {
    if (this->isEmpty()) {
        Node *curr = new Node;
        curr->info = c;
        curr->prev = nullptr;
        curr->next = nullptr;
        count++;
        tail = curr;
        front = curr;
    } else {
        Node *curr = new Node;
        curr->info = c;
        curr->prev = nullptr;
        front->prev = curr;
        curr->next = front;
        count++;
        front = curr;
    }
}

/* popFromFront
 * Purpose: Removes the first element from the linked list
 * Parameters: none
 * Returns: nothing
 */
void CharLinkedList::popFromFront() {
    if (this->isEmpty()) {
        throw runtime_error("cannot pop from empty LinkedList");
    }

    if (count > 1) {
        Node *temp = front;
        front = temp->next;
        front->prev= nullptr;
        temp->next = nullptr;
        delete temp;
        count--;    
    } else {
        // Count is 1  
        Node *temp = front;
        delete temp;
        front = nullptr;
        tail = nullptr;
        count = 0;
    }
}

/* popFromBack
 * Purpose: Removes the last element from the linked list
 * Parameters: none
 * Returns: nothing
 */
void CharLinkedList::popFromBack() {

    if (this->isEmpty()) {
        throw runtime_error("cannot pop from empty LinkedList");
    }

    if (count > 1) {
        Node *temp = tail;
        tail = temp->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        count--;    
    } else {
        // Count is 1  
        Node *temp = front;
        delete temp;
        front = nullptr;
        tail = nullptr;
        count = 0;
    }  
}

/* insertAt
 * Purpose: Inserts given new char at given index
 * Parameters: an element (char), and index (int)
 * Returns: nothing
 */
void CharLinkedList::insertAt(char c, int index) {
    if (index < 0 || index > count) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(count) + "]");
    }
    if (index == count) {
        this->pushAtBack(c);
        return;
    } else if (index == 0) {
        this->pushAtFront(c);
        return;
    }
    Node *curr = front;
    Node *newnode = new Node;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    newnode->prev = curr;
    curr = curr->next;
    newnode->next = curr;
    newnode->prev->next = newnode;
    curr->prev = newnode;
    newnode->info = c;
    count++;
}

/* insertInOrder
 * Purpose: Inserts given new char in alphabetical order
 * Parameters: an element (char)
 * Returns: nothing
 */
void CharLinkedList::insertInOrder(char c) {
    Node *curr = front;
    int index = 0;
    while (curr && curr->info < c) {
        curr = curr->next;
        index++;
    }
    this->insertAt(c, index);
}

/* removeAt
 * Purpose: Removes the element at the specified index
 * Parameters: index (int)
 * Returns: nothing
 */
void CharLinkedList::removeAt(int index) {
    if (index < 0 || index >= count) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(count) + ")");
    }
    if (index == count - 1) {
        this->popFromBack();
        return;
    } else if (index == 0) {
        this->popFromFront();
        return;
    }
    Node *curr = front;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->next = nullptr;
    curr->prev = nullptr;
    delete curr;
    count--;
}

/* replaceAt
 * Purpose: Replaces the element at the specified index with the specified char
 * Parameters: element (char), index (int)
 * Returns: nothing
 */
void CharLinkedList::replaceAt(char c, int index) {
    if (index < 0 || index >= count) {
        throw range_error("index (" + to_string(index) + ") not in range [0.." + to_string(count) + ")");
    }
    Node *curr = front;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    curr->info = c;
}

/* concatenate
 * Purpose: Adds a copy of the linked list passed in to the end 
 * of the linked list called from
 * Parameters: CharLinkedList pointer
 * Returns: nothing
 */
void CharLinkedList::concatenate(CharLinkedList *other) {
    if (this->isEmpty() && !other->isEmpty()) {
        Node *curr = other->front;

        front = new Node;
        Node *newcurr = front;
        Node *prev = nullptr;

        while (curr->next) {
            newcurr->info = curr->info;
            curr = curr->next;
            Node *next = new Node;
            newcurr->next = next;
            next->prev = newcurr;
            prev = newcurr;
            newcurr = newcurr->next;
        }
    
        newcurr->info = curr->info;
        newcurr->next = nullptr;
        newcurr->prev = prev;
        tail = newcurr;
        tail->next = nullptr;

        count = other->count;
    } else if (other->isEmpty()) {
        return;
    } else {
        CharLinkedList temp = CharLinkedList(*other);
        Node *curr = temp.front;
        Node *newcurr = new Node;
        tail->next = newcurr;
        newcurr->prev = tail;
        Node *prev = nullptr;

        while (curr->next) {
            newcurr->info = curr->info;
            curr = curr->next;
            Node *next = new Node;
            newcurr->next = next;
            next->prev = newcurr;
            prev = newcurr;
            newcurr = newcurr->next;
        }

        newcurr->info = curr->info;
        newcurr->next = nullptr;
        newcurr->prev = prev;
        tail = newcurr;
        tail->next = nullptr;

        count += other->count;
    }
}


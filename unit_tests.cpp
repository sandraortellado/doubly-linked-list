/*
 *  unit_tests.cpp
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  FILE PURPOSE HERE
 *
 */
#include <iostream>
#include <cassert>
#include "CharLinkedList.h"

using namespace std;

void constructor_test() {
    //default constructor
    CharLinkedList basic = CharLinkedList();
    assert(basic.isEmpty());
    assert(basic.size() == 0);

    // //secondconstructor
    CharLinkedList solo = CharLinkedList('a');
    assert(solo.size() == 1);
    assert(solo.elementAt(0) == 'a');

    // //third constructor
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList charL = CharLinkedList(tarr, 4);
    assert(charL.size() == 4);
    assert(charL.elementAt(0) == 'a');
    assert(charL.elementAt(1) == 'b');
    assert(charL.elementAt(2) == 'c');
    assert(charL.elementAt(3) == 'd');
    
    //copy constructor
    CharLinkedList copy = CharLinkedList(charL);
    assert(copy.size() == 4);
    assert(copy.elementAt(0) == 'a');
    assert(copy.elementAt(1) == 'b');
    assert(copy.elementAt(2) == 'c');
    assert(copy.elementAt(3) == 'd');
}

void assignment_test() {
    CharLinkedList orig_solo = CharLinkedList('b');
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList newlist = CharLinkedList(tarr, 4);
    CharLinkedList backup = newlist;
    newlist = orig_solo;
    assert(newlist.elementAt(0) == 'b');
    assert(newlist.size() == 1);
    newlist = backup;
    assert(newlist.elementAt(0) == 'a');
    assert(newlist.size() == 4);
}

void clear_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList charL = CharLinkedList(tarr, 4);
    assert(charL.size() == 4);
    charL.clear();
    assert(charL.size() == 0);
    assert(charL.isEmpty());
}

void first_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList charL = CharLinkedList(tarr, 4);
    assert(charL.first() == 'a');

    try {
       CharLinkedList empty = CharLinkedList();
       empty.first(); 
       assert(false);
    } catch (runtime_error) {
    }
}

void last_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList charL = CharLinkedList(tarr, 4);
    assert(charL.last() == 'd');

    try {
       CharLinkedList empty = CharLinkedList();
       empty.first(); 
       assert(false);
    } catch (runtime_error) {
    }
}

void elementAt_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList echar = CharLinkedList(tarr, 4);
    assert(echar.elementAt(2) == 'c');
    try {
       echar.elementAt(5);
       echar.elementAt(-1);
       assert(false);
    } catch (range_error) {
    }
}

void print_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList schar = CharLinkedList(tarr, 4);
    // schar.print();

    CharLinkedList empty = CharLinkedList();
    // empty.print();
}

void pushAtBack_test() {
    CharLinkedList solo = CharLinkedList('a');
    solo.pushAtBack('b');
    assert(solo.elementAt(1) == 'b');

    CharLinkedList empty = CharLinkedList();
    empty.pushAtBack('a');
    assert(empty.elementAt(0) == 'a');
}

void pushAtFront_test() {
    CharLinkedList solo = CharLinkedList('a');
    solo.pushAtFront('b');
    assert(solo.elementAt(1) == 'a');

    CharLinkedList empty = CharLinkedList();
    empty.pushAtFront('a');
    assert(empty.elementAt(0) == 'a');
}

void popFromBack_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList echar = CharLinkedList(tarr, 4);
    assert(echar.size() == 4);
    echar.popFromBack();
    assert(echar.size() == 3);
    echar.popFromBack();
    echar.popFromBack();
    echar.popFromBack();
    assert(echar.isEmpty());
}

void popFromFront_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList echar = CharLinkedList(tarr, 4);
    assert(echar.size() == 4);
    echar.popFromFront();
    assert(echar.size() == 3);
    assert(echar.elementAt(0) == 'b');
    echar.popFromFront();
    echar.popFromFront();
    echar.popFromFront();
    assert(echar.isEmpty());
}

void insertAt_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList echar = CharLinkedList(tarr, 4);
    assert(echar.size() == 4);
    echar.insertAt('f', 1);
    assert(echar.elementAt(1) == 'f');
    assert(echar.size() == 5);

    echar.insertAt('o', 0);
    assert(echar.elementAt(0) == 'o');

    echar.insertAt('l', 6);
    assert(echar.elementAt(6) == 'l');
    assert(echar.size() == 7);   

    try {
       echar.elementAt(7);
       echar.elementAt(-1);
       assert(false);
    } catch (range_error) {
    } 
}

void insertInOrder_test() {
    char tarr[3];
    tarr[0] = 'b';
    tarr[1] = 'd';
    tarr[2] = 'e';
    CharLinkedList echar = CharLinkedList(tarr, 3);
    assert(echar.size() == 3);

    echar.insertInOrder('c');
    assert(echar.elementAt(1) == 'c');
    echar.insertInOrder('a');
    assert(echar.elementAt(0) == 'a');
    echar.insertInOrder('f');
    assert(echar.elementAt(5) == 'f');
}

void removeAt_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList echar = CharLinkedList(tarr, 4);
    assert(echar.size() == 4);
    echar.removeAt(2);
    assert(echar.elementAt(2) == 'd');
    echar.removeAt(2);
    assert(echar.size() == 2);
    echar.removeAt(0);
    assert(echar.elementAt(0) == 'b');

    try {
       echar.elementAt(7);
       echar.elementAt(-1);
       assert(false);
    } catch (range_error) {
    }
}

void replaceAt_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'c';
    tarr[3] = 'd';
    CharLinkedList echar = CharLinkedList(tarr, 4);
    echar.replaceAt('e', 3);
    assert(echar.elementAt(3) == 'e');
    echar.replaceAt('e', 0);
    assert(echar.elementAt(0) == 'e');
    echar.replaceAt('e', 2);
    assert(echar.elementAt(2) == 'e');

    try {
       echar.elementAt(7);
       echar.elementAt(-1);
       assert(false);
    } catch (range_error) {
    }
}

void concatenate_test() {
    char tarr[4];
    tarr[0] = 'a';
    tarr[1] = 'b';
    tarr[2] = 'd';
    tarr[3] = 'e';

    char tarr2[4];
    tarr2[0] = 'a';
    tarr2[1] = 'b';
    tarr2[2] = 'd';
    tarr2[3] = 'e';
    CharLinkedList charL = CharLinkedList(tarr, 4);
    CharLinkedList charL2 = CharLinkedList(tarr2, 4);
    charL.concatenate(&charL2);
    assert(charL.elementAt(2) == 'd');
    assert(charL.elementAt(6) == 'd');
    assert(charL.elementAt(5) == 'b');
    assert(charL.first() == 'a');
    assert(charL.last() == 'e');

    CharLinkedList empty = CharLinkedList();
    CharLinkedList charL3 = CharLinkedList(tarr, 4);
    empty.concatenate(&charL3);
    assert(empty.elementAt(2) == 'd');
    assert(empty.elementAt(0) == 'a');
    assert(empty.elementAt(3) == 'e');

    CharLinkedList empty2 = CharLinkedList();
    CharLinkedList charL4 = CharLinkedList(tarr, 4);
    charL4.concatenate(&empty2);
    assert(charL4.size() == 4);

    try {
       CharLinkedList empty3 = CharLinkedList();
       empty3.first(); 
       assert(false);
    } catch (runtime_error) {
    }
}

int main() {
    constructor_test();
    assignment_test();
    clear_test();
    first_test();
    last_test();
    elementAt_test();
    print_test();
    pushAtBack_test();
    pushAtBack_test();
    popFromFront_test();
    popFromBack_test();
    insertAt_test();
    insertInOrder_test();
    removeAt_test();
    replaceAt_test();
    concatenate_test();
}
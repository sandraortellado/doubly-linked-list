README

A) Title and Author
Title: Linked Lists
Author: Sandra Ortellado

B) Purpose
The purpose of this program is to define, implement,
and test the doubly linked character linked list class, CharLinkedList.

C) Help Received
Linked lists parts 1 and 2 topics in Canvas.

D) Files Provided
* CharLinkedList.cpp - Define all member functions of the CharLinkedList class
* CharLinkedList.h - Header file defining CharLinkedList class
* unit_tests.cpp - Test functionality of class and member functions
* README.md - Outline purpose and functionality of program

E) How to compile and run
To compile and run, enter 'make ; ./test_files' in command line.

F) Data Strcutures
Linked List:
A linked list is a linear data structure, whose nodes are stored randomly
in memory and are allocated during run time. Each node consists of value/data
and a pointer/link which is the address of the next node in the linked list.
A doubly linked list contains a pointer to the next as well
as the previous node in sequence, so it can be traverssed in 
the backward direction as well.

A linked list has the advantages of being dynamic, easily implemented,
easily deleted and inserteed into, and not memory wasting.
However, it requires more memory for the pointers and is more
time consuming to traverse compared to an array, as a particular element
cannot be accessed without traversal.

G) Testing strategy
To test the program, I created a function to call each of the member functions
of the CharLinkedList class and asserted the expected result,
as well as including try and catch for the cases that should trigger
an error thrown. I wrote and tested incrementally and compiled and ran
regularly, including with valgrind to check for memory leaks.

Questions:

1. Removing and inserting functions were more easily implmented than in the
array list assignment, since elements did not need to be shifted to do so,
but instead pointers were simply changed.

2. Concatenating or copying lists or any function that required looping 
through the linked list was more difficult than the array list,
since I could not rely on index as the elements were not next to each other
in memory. Copying also made the program more vulnerable to double frees or
leaks because of all the extra pointers involved.

3. To switch to a linked list from an array list, you would need to add
front and tail pointers as well as a node struct to your class, and the
node struct would need to include both a next and prev pointer.
/*
 *  CharLinkedList.h
 *  YOUR NAME HERE
 *  DATE CREATED
 *
 *  CS 15 HW 2
 *
 *  FILE PURPOSE HERE
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

class CharLinkedList {
    public:

        int count;

        CharLinkedList();
        CharLinkedList(char c);
        CharLinkedList(char *arr, int size);
        CharLinkedList(const CharLinkedList &other);
        void operator=(const CharLinkedList &other);
        ~CharLinkedList();
        bool isEmpty();
        void clear();
        int size();
        char first();
        char last();
        char elementAt(int index);
        void print();
        void pushAtBack(char c);
        void pushAtFront(char c);
        void popFromFront();
        void popFromBack();
        void removeAt(int index);
        void replaceAt(char c, int index);
        void insertAt(char c, int index);
        void insertInOrder(char c);
        void concatenate(CharLinkedList *other);
        
    private:
    struct Node {
        char info;
        Node *prev, *next;
    };

    Node *front;
    Node *tail;  
};

#endif

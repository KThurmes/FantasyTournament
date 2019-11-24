#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include "Node.hpp"

class DLList{
    private:
        Node* head;
        Node* tail;
    public:
        DLList();
        void deleteDLList();
        Node* peekFront();
        Node* popFront();
        Node* getTail();
        void addToBack(Node* newGuy);
        void addToBack(Character*);
        void traverse();
        void deleteFirstNode();
        void printHeadVal();
        bool isEmpty();
        ~DLList();
};

#endif
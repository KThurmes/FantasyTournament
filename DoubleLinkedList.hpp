#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include "Node.hpp"

class DLList
{
private:
    Node *head;
    Node *tail;

public:
    DLList();
    void deleteDLList();
    Node *popFront();
    void addToBack(Node *newGuy);
    void addToBack(Character *);
    void traverse();
    void traverseReverse();
    void deleteFirstNode();
    void printHeadVal();
    bool isEmpty();
    ~DLList();
};

#endif
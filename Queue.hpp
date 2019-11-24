#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"
#include "Character.hpp"

class Queue{
    private:
        QueueNode* head;
        QueueNode* tail;
    public:
        Queue();
        bool isEmpty();
        void addBack(Character*);
        void addNodeBack(QueueNode*);
        Character* getFront();
        void removeFront();
        void printQueue();
        void printFront();
        ~Queue();
        QueueNode* popFront();
};

#endif
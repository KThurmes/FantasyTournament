#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include "Character.hpp"


class QueueNode {

    private:
        Character* chara;
        QueueNode* next = 0;
        QueueNode* prev = 0;

    public:
        QueueNode(Character*);
        ~QueueNode();
        void setCharacter(Character*);
        void setNext(QueueNode*);
        void setPrev(QueueNode*);
        QueueNode* getNext();
        QueueNode* getPrev();
        Character* getCharacter();
};

#endif
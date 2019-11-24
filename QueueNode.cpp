#include "QueueNode.hpp"
#include "Character.hpp"
#include <iostream>

using std::cout;

QueueNode::QueueNode(Character *character)
{
    chara = character;
}

QueueNode::~QueueNode()
{
    delete chara;
}

void QueueNode::setCharacter(Character *character)
{
    this->chara = character;
}

void QueueNode::setNext(QueueNode *n)
{
    next = n;
}

void QueueNode::setPrev(QueueNode *p)
{
    prev = p;
}

QueueNode *QueueNode::getNext()
{
    return next;
}

QueueNode *QueueNode::getPrev()
{
    return prev;
}

Character *QueueNode::getCharacter()
{
    return chara;
}
/********************************************************************* 
** Author: Katheen Thurmes
** Date: 5 Nov., 2019 (updated 24 Nov., 2019)
** Description: Node implements a node that will be used to construct 
a linked list. This implementation contains an int value and each 
node has a pointer to the next node and the previous node. It has 
setter and getter functions and a function to print its value.
*********************************************************************/

#include "Node.hpp"
#include "Character.hpp"
#include <iostream>
using std::cout;

/********************************************************************* 
** Description: the Node constructor sets the pointers to the next 
and previous nodes to null, and the val to the input value.
*********************************************************************/
Node::Node(Character *character)
{
    this->next = 0;
    this->prev = 0;
    this->chara = character;
}

void Node::printValue()
{
    cout << chara->getName();
}

Node *Node::getNext()
{
    return next;
}

Node *Node::getPrev()
{
    return prev;
}

void Node::setNext(Node *newGuy)
{
    next = newGuy;
}

void Node::setPrev(Node *newGuy)
{
    prev = newGuy;
}

Character *Node::getCharacter()
{
    return this->chara;
}

void Node::deleteNode()
{
    delete chara;
    cout << "Deleting a node!\n";
}
Node::~Node()
{
    delete chara;
}
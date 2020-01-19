/********************************************************************* 
** Author: Katheen Thurmes
** Date: 5 Nov., 2019 (updated 24 Nov., 2019)
** Description: DoubleLinkedList (or the DLList class) implements a 
linked list in which each node has a pointer to the next and previous 
node. The list itself has only two data members: a pointer to the 
head node and a pointer to the tail node. It implements a number of 
manipulations, including adding and subtracting nodes, printing the 
list, and printing the list backwards.
*********************************************************************/

#include "DoubleLinkedList.hpp"
#include <iostream>
using std::cout;
using std::endl;

/********************************************************************* 
** Description: the DLList constructor sets the pointers to the head 
and tail nodes to null, thus creating an empty list.
*********************************************************************/
DLList::DLList()
{
    head = 0;
    tail = 0;
}

/********************************************************************* 
** Description: popFront takes the first node in the linked list, 
removes it from the list, and returns the node.
*********************************************************************/
Node *DLList::popFront()
{
    Node *toReturn = head;
    head = head->getNext();
    //Check that the list isn't already empty
    if (head != 0)
    {
        head->setPrev(0);
    }
    return toReturn;
}

/********************************************************************* 
** Description: addToBack(Character*), along with its helper function, 
addToBack(Node*), creates a new Node with inputted Character stored 
inside, add the Node object to the head of the list, and re-assigns 
the head pointer accordingly.
*********************************************************************/
void DLList::addToBack(Character *value)
{
    Node *newGuy = new Node(value);
    addToBack(newGuy);
}

/********************************************************************* 
** Description: addToHead(Node*) is a helper function for adding a 
new Node to the head of the linked list. The reason for this function 
to exist separately from the addToHead(Character*) function is to make 
the class a little more reusable, in that this function can be used to 
add a Node that contains any kind of data, rather than just a 
Character object.
*********************************************************************/
void DLList::addToBack(Node *newGuy)
{
    //If there's nothing in the list yet, head and tail both point to the new node
    if (head == 0)
    {
        head = newGuy;
        tail = newGuy;
        newGuy->setNext(0);
        newGuy->setPrev(0);
    }

    //Otherwise, rearrage tail pointer, and the "next" and "prev" pointers of affected nodes.
    else
    {
        newGuy->setPrev(this->tail);
        (this->tail)->setNext(newGuy);
        newGuy->setNext(0);
        this->tail = newGuy;
    }
}

/********************************************************************* 
** Description: traverse will print out the names of the Characters 
in the linked list.
*********************************************************************/
void DLList::traverse()
{
    Node *current;
    current = this->head;

    //Check if list is empty
    if (current == 0)
    {
        cout << "The list is empty.\n";
    }

    else
    {
        //Go through and print each node's value to the terminal.
        while (current != 0)
        {
            current->printValue();
            cout << " ";
            current = current->getNext();
        }
        cout << endl;
    }
}
/********************************************************************* 
** Description: traverseReverse will print out the names of the 
Characters in the linked list backwards.
*********************************************************************/
void DLList::traverseReverse()
{
    Node *current;
    current = this->tail;

    //Check if list is empty
    if (current == 0)
    {
        cout << "The list is empty.\n";
    }

    else
    {
        //Go through and print each node's value to the terminal.
        while (current != 0)
        {
            current->printValue();
            cout << " ";
            current = current->getPrev();
        }
        cout << endl;
    }
}

/********************************************************************* 
** Description: deleteFirstNode deletes the first Node in the list 
and frees the memory, then re-assigns head pointer as well as the 
pointers inside adjacent Node of the Node removed.
*********************************************************************/
void DLList::deleteFirstNode()
{
    //If the list isn't empty:
    if (this->head != 0)
    {
        //If there are at least two nodes in the list, reassign pointers and free old head
        if (head->getNext() != 0)
        {
            this->head = head->getNext();
            delete head->getPrev();
            head->setPrev(0);
        }
        //If we're deleting the last node in the list:
        else
        {
            delete head;
            this->head = 0;
            this->tail = 0;
        }
    }
    else
    {
        cout << "Error: There are no nodes to delete!" << endl;
    }
}

/********************************************************************* 
** Description: printHeadVal prints out the value in the head Node
*********************************************************************/
void DLList::printHeadVal()
{
    cout << "The value in the head node is: ";
    head->printValue();
    cout << endl;
}

/********************************************************************* 
** Description: isEmpty returns true if there are no more nodes in 
the list.
*********************************************************************/
bool DLList::isEmpty()
{
    return (head == 0);
}

/********************************************************************* 
** Description: deleteDLList calls deleteFirstNode until the list is 
empty.
*********************************************************************/
void DLList::deleteDLList()
{
    while (this->head != 0)
    {
        deleteFirstNode();
    }
}

DLList::~DLList()
{
    deleteDLList();
}
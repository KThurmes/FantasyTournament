#include "Queue.hpp"
#include <iostream>
#include "Character.hpp"

using std::cout;
using std::endl;

Queue::Queue(){
    head = 0;
}

Queue::~Queue(){
    while (!isEmpty()){
        removeFront();
    }
}

void Queue::addBack(Character* character){
    QueueNode* node = new QueueNode(character);
    
    if (!isEmpty()){
        head->getPrev()->setNext(node);
        node->setNext(head);
        node->setPrev(head->getPrev());
        head->setPrev(node);
    }

    else{
        head = node;
        head->setPrev(node);
        head->setNext(node);
    }
}

void Queue::addNodeBack(QueueNode* qNode){
    if (!isEmpty()){
        head->getPrev()->setNext(qNode);
        qNode->setNext(head);
        qNode->setPrev(head->getPrev());
        head->setPrev(qNode);
    }

    else{
        head = qNode;
        head->setPrev(qNode);
        head->setNext(qNode);
    }
}

bool Queue::isEmpty(){
    return (head == 0);
}

void Queue::printQueue(){
    QueueNode* current = head;
    if (isEmpty()){
        cout << "The queue is empty!" << endl;
    }
    else{
        //cout << "Here are the values in the queue:\n";
        //current->printValsLong();
        cout << current->getCharacter()->getName() << " ";
        while(current->getNext() != head){
            current = current-> getNext();
            //current->printValsLong();
            cout << current->getCharacter()->getName() << " ";
        }
        //cout << " -> " << current -> next-> val;
        cout << endl;
    }
}

void Queue::printFront(){
    if (isEmpty()){
        cout << "The queue is empty!" << endl;
    }
    else{
        cout << "The front value is: " << getFront() << endl;
    }
}

Character* Queue::getFront(){
    return head->getCharacter();
}

void Queue::removeFront(){

    if(isEmpty()){
        cout << "The queue is empty!" << endl;
    }
    //If it's the last node in the queue, make head pointer = null
    else if (head->getNext() == head){
        head->~QueueNode();
        head = 0;
    }

    else{
        head->getNext()->setPrev(head->getPrev());
        head = head->getNext();
        (head-> getPrev()->getNext())->~QueueNode();
        head->getPrev()->setNext(head);
    }
}

QueueNode* Queue::popFront(){
    QueueNode* toReturn;

    if (head->getNext() == head){
        toReturn = head;
        head = 0;
    }

    else{
        toReturn = head;
        head->getNext()->setPrev(head->getPrev());
        head = head->getNext();
        head -> getPrev()->setNext(head);
    }

    return toReturn;
}
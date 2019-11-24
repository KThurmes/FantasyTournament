#ifndef NODE_HPP
#define NODE_HPP
#include "Character.hpp"

class Node{
    private:
        Node* next;
        Node* prev;
        Character* chara;
    public:
        Node(Character* charac);
        void printValue();
        Node* getNext();
        Node* getPrev();
        void setNext(Node*);
        void setPrev(Node*);
        Character* getCharacter();
        void deleteNode();
        ~Node();
};

#endif
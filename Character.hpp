/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: Character is a purely virtual class that describes a 
character in a fantasy-themed battle game implemented for OSU's CS162 
in Fall 2019.
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Die.hpp"
#include <string>
using std::string;

class Character
{
protected:
    string name;
    Die **attackDice;
    int nAttackDice;
    Die **defenseDice;
    int nDefenseDice;
    int armor;
    int strength;

public:
    //The fact that pure virtual destructors must be defined in a base class found here: https://www.studytonight.com/cpp/virtual-destructors.php
    //Accessed 11/2/19
    virtual int attack() = 0;
    virtual int rollDefense() = 0;
    virtual int defense(int, int) = 0;
    virtual ~Character(){};
    virtual string getCharacterName() = 0;
    virtual int getArmor() = 0;
    virtual int getStrength() = 0;
    virtual void printStats() = 0;
    virtual string getName() = 0;
    virtual void recover() = 0;
};

#endif
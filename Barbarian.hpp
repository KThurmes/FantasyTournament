/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: Barbarian is an implementation of the Character 
virtual class. It has no special powers.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
#include <string>
using std::string;

class Barbarian : public Character
{
private:
public:
    string getName();
    Barbarian(string);
    int attack();
    int rollDefense();
    int defense(int, int);
    string getCharacterName();
    ~Barbarian();
    int getArmor()
    {
        return armor;
    }
    int getStrength()
    {
        return strength;
    }
    void printStats();
    void recover();
};

#endif
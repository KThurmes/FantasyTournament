/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: Vampire is an implementation of the Character 
virtual class. Vampire uses "Charm" to ensure that there is a 50-50 
chance that it will not take any damage on a given round.
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"
#include <string>
using std::string;

class Vampire : public Character
{
private:
public:
    string getName();
    Vampire(string);
    int attack();
    int rollDefense();
    int defense(int, int);
    string getCharacterName();
    ~Vampire();
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
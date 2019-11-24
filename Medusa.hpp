/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: Medusa is an implementation of the Character 
virtual class. Medusa can use "Glare" to kill a player in one hit if 
the character rolls a 12 in its attack.
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"
#include <string>
using std::string;

class Medusa : public Character
{
private:
public:
    string getName();
    Medusa(string);
    int attack();
    int rollDefense();
    int defense(int, int);
    string getCharacterName();
    ~Medusa();
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
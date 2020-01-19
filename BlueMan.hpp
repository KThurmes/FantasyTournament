/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: BlueMan is an implementation of the Character 
virtual class. A BlueMan character is actually a collection of blue 
men. For every 4 strength points the BlueMan loses in battle, the 
character loses one of its defense dice.
*********************************************************************/
#ifndef BLUEMAN_HPP
#define BLUEMAN_HPP

#include "Character.hpp"
#include <string>
using std::string;

class BlueMan : public Character
{
private:
public:
    string getName();
    BlueMan(string);
    int attack();
    int rollDefense();
    int defense(int, int);
    string getCharacterName();
    ~BlueMan();
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
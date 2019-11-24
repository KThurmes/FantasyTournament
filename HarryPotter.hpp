/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: Harry Potter is an implementation of the Character 
virtual class. If a HarryPotter character dies, it uses "Hogwarts" 
and comes back to life with 20 strength points. The character can 
only use Hogarts once.
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"
#include <string>
using std::string;

class HarryPotter : public Character
{
private:
    bool secondLife;

public:
    string getName();
    HarryPotter(string);
    int attack();
    int rollDefense();
    int defense(int, int);
    string getCharacterName();
    ~HarryPotter();
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
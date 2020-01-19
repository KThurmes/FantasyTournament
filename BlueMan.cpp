/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019 (updated 24 Nov., 2019)
** Description: BlueMan is an implementation of the Character 
virtual class. A BlueMan character is actually a collection of blue 
men. For every 4 strength points the BlueMan loses in battle, the 
character loses one of its defense dice.
*********************************************************************/

#include "BlueMan.hpp"
#include "Die.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using std::ceil;
using std::cout;
using std::endl;
using std::string;

/********************************************************************* 
** Description: The constructor sets up the character with the 
appropriate stats according to its type.
*********************************************************************/
BlueMan::BlueMan(string name)
{
    this->name = name;

    //Set up the sets of dice
    //Set up attack dice
    nAttackDice = 2;
    attackDice = new Die *[nAttackDice];
    for (int i = 0; i < nAttackDice; i++)
    {
        attackDice[i] = new Die(10);
    }
    //Set up defense dice
    nDefenseDice = 3;
    defenseDice = new Die *[nDefenseDice];
    for (int j = 0; j < nDefenseDice; j++)
    {
        defenseDice[j] = new Die(6);
    }

    //Set up Armor and Strength
    this->armor = 3;
    this->strength = 12;
}

/********************************************************************* 
** Description: attack rolls all the attacker's attack dice and 
returns the value of the roll.
*********************************************************************/
int BlueMan::attack()
{

    int attackRoll = 0;

    //Roll each die in turn, adding the number to the total
    for (int i = 0; i < nAttackDice; i++)
    {
        attackRoll += attackDice[i]->roll();
    }

    //Print out value of attack roll
    //cout << "Attack roll: " << attackRoll << endl;

    return attackRoll;
}

/********************************************************************* 
** Description: rollDefense rolls all the defender's defense dice 
and returns the value of the roll.
*********************************************************************/
int BlueMan::rollDefense()
{
    int rollSum = 0;
    //Use of ceil used with reference to http://www.cplusplus.com/reference/cmath/
    //Accessed 11/24/19
    //BlueMan loses one defense die for every 4 health points it loses
    int nRolls = ceil(strength / 4.0);

    //Roll each die in turn, adding the number to the total
    for (int i = 0; i < nRolls; i++)
    {
        rollSum += defenseDice[i]->roll();
    }

    //Print out value of defense roll
    return rollSum;
}

/********************************************************************* 
** Description: defense takes the results of the defense and attack 
rolls, and updates the defensive character's stats accordingly. It 
returns the net damage that the defense has taken.
*********************************************************************/
int BlueMan::defense(int attackRoll, int defenseRoll)
{
    //Damage is attack roll - defense roll - armor
    int netDamage = attackRoll - (defenseRoll + this->armor);

    //Don't let net damage go below 0
    if (netDamage < 0)
    {
        netDamage = 0;
    }

    //Update strength
    strength -= netDamage;

    //Don't let health go below 0
    if (strength < 0)
    {
        strength = 0;
    }

    return netDamage;
}

/********************************************************************* 
** Description: getCharacterName returns the type of character as a 
string.
*********************************************************************/
string BlueMan::getCharacterName()
{
    return "Blue Man";
}

/********************************************************************* 
** Description: printStats prints the type, name, armor, and strength 
of the character to the terminal.
*********************************************************************/
void BlueMan::printStats()
{
    cout << "Type: Blue Man" << endl;
    cout << "Name: " << name << endl;
    cout << "Armor: " << armor << endl;
    cout << "Strength: " << strength << endl;
}

/********************************************************************* 
** Description: getName returns the character's name as a string.
*********************************************************************/
string BlueMan::getName()
{
    return name;
}

/********************************************************************* 
** Description: Destructor deletes the attack and defense dice along 
with their pointers.
*********************************************************************/
BlueMan::~BlueMan()
{
    //Delete attack dice
    for (int i = 0; i < nAttackDice; i++)
    {
        delete attackDice[i];
    }
    //Delete defense dice using original number of dice
    for (int j = 0; j < nDefenseDice; j++)
    {
        delete defenseDice[j];
    }
    delete[] attackDice;
    delete[] defenseDice;
}

/********************************************************************* 
** Description: recover() allows the character to regain half of the 
strength they've lost
*********************************************************************/
void BlueMan::recover()
{
    int strengthLost = 12 - strength;
    strength = strength + (strengthLost / 2);
}
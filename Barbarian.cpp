/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019 (updated 24 Nov., 2019)
** Description: Barbarian is an implementation of the Character 
virtual class. It has no special powers.
*********************************************************************/

#include "Barbarian.hpp"
#include "Die.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <cstdlib>
#include <ctime>

/********************************************************************* 
** Description: The constructor sets up the character with the 
appropriate stats according to its type.
*********************************************************************/
Barbarian::Barbarian(string name)
{
    this->name = name;

    //Set up the sets of dice
    //Set up attack dice
    nAttackDice = 2;
    attackDice = new Die *[nAttackDice];
    for (int i = 0; i < nAttackDice; i++)
    {
        attackDice[i] = new Die(6);
    }
    //Set up defense dice
    nDefenseDice = 2;
    defenseDice = new Die *[nDefenseDice];
    for (int j = 0; j < nDefenseDice; j++)
    {
        defenseDice[j] = new Die(6);
    }

    //Set up Armor and Strength
    this->armor = 0;
    this->strength = 12;
}

/********************************************************************* 
** Description: attack rolls all the attacker's attack dice and 
returns the value of the roll.
*********************************************************************/
int Barbarian::attack()
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
int Barbarian::rollDefense()
{
    int rollSum = 0;

    //Roll each die in turn, adding the number to the total
    for (int i = 0; i < nDefenseDice; i++)
    {
        rollSum += defenseDice[i]->roll();
    }

    //Print out value of defense roll
    //cout << "Defense Roll: " << rollSum << endl;
    return rollSum;
}

/********************************************************************* 
** Description: defense takes the results of the defense and attack 
rolls, and updates the defensive character's stats accordingly. It 
returns the net damage that the defense has taken.
*********************************************************************/
int Barbarian::defense(int attackRoll, int defenseRoll)
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
string Barbarian::getCharacterName()
{
    return "Barbarian";
}

/********************************************************************* 
** Description: printStats prints the type, name, armor, and strength 
of the character to the terminal.
*********************************************************************/
void Barbarian::printStats()
{
    cout << "Type: Barbarian" << endl;
    cout << "Name: " << name << endl;
    cout << "Armor: " << armor << endl;
    cout << "Strength: " << strength << endl;
}

/********************************************************************* 
** Description: getName returns the character's name as a string.
*********************************************************************/
string Barbarian::getName()
{
    return name;
}

/********************************************************************* 
** Description: Destructor deletes the attack and defense dice along 
with their pointers.
*********************************************************************/
Barbarian::~Barbarian()
{

    //Delete attack dice
    for (int i = 0; i < nAttackDice; i++)
    {
        delete attackDice[i];
    }
    //Delete defense dice
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
void Barbarian::recover()
{
    int strengthLost = 12 - strength;
    strength = strength + (strengthLost / 2);
}
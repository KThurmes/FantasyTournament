/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019 (updated 24 Nov., 2019)
** Description: Vampire is an implementation of the Character 
virtual class. Vampire uses "Charm" to ensure that there is a 50-50 
chance that it will not take any damage on a given round.
*********************************************************************/
#include "Vampire.hpp"
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
Vampire::Vampire(string name)
{
    //Seed random on time of creation of a vampire
    srand(time(NULL));

    this->name = name;

    //Set up the sets of dice
    //Set up attack dice
    nAttackDice = 1;
    attackDice = new Die *[nAttackDice];
    for (int i = 0; i < nAttackDice; i++)
    {
        attackDice[i] = new Die(12);
    }
    //Set up defense dice
    nDefenseDice = 1;
    defenseDice = new Die *[nDefenseDice];
    for (int j = 0; j < nDefenseDice; j++)
    {
        defenseDice[j] = new Die(6);
    }

    //Set up Armor and Strength
    this->armor = 1;
    this->strength = 18;
}

/********************************************************************* 
** Description: attack rolls all the attacker's attack dice and 
returns the value of the roll.
*********************************************************************/
int Vampire::attack()
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
int Vampire::rollDefense()
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
int Vampire::defense(int attackRoll, int defenseRoll)
{
    //Damage is attack roll - defense roll - armor
    int netDamage = attackRoll - (defenseRoll + this->armor);

    //Implement 50% chance of not taking any damage
    //Choose random number between 0 and 1.
    int nRand = (rand() % 2);

    //If random number is 0, then vampire doesn't take damage.
    if (nRand == 0)
    {
        netDamage = 0;
    }

    //Don't let netDamage go below 0.
    else if (netDamage < 0)
    {
        netDamage = 0;
    }

    //Update strength
    strength -= netDamage;

    return netDamage;
}

/********************************************************************* 
** Description: getCharacterName returns the type of character as a 
string.
*********************************************************************/
string Vampire::getCharacterName()
{
    return "Vampire";
}

/********************************************************************* 
** Description: printStats prints the type, name, armor, and strength 
of the character to the terminal.
*********************************************************************/
void Vampire::printStats()
{
    cout << "Type: Vampire" << endl;
    cout << "Name: " << name << endl;
    cout << "Armor: " << armor << endl;
    cout << "Strength: " << strength << endl;
}

/********************************************************************* 
** Description: getName returns the character's name as a string.
*********************************************************************/
string Vampire::getName()
{
    return name;
}

/********************************************************************* 
** Description: Destructor deletes the attack and defense dice along 
with their pointers.
*********************************************************************/
Vampire::~Vampire()
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
void Vampire::recover()
{
    int strengthLost = 18 - strength;
    strength = strength + (strengthLost / 2);
}
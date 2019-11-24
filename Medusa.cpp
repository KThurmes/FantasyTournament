/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: Medusa is an implementation of the Character 
virtual class. Medusa can use "Glare" to kill a player in one hit if 
the character rolls a 12 in its attack.
*********************************************************************/

#include "Medusa.hpp"
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
Medusa::Medusa(string name){
    this->name = name;
    
    //Set up the sets of dice
    //Set up attack dice
    nAttackDice = 2;
    attackDice = new Die*[nAttackDice];
    for (int i = 0; i < nAttackDice; i++){
        attackDice[i] = new Die(6);
    }
    //Set up defense dice
    nDefenseDice = 1;
    defenseDice = new Die*[nDefenseDice];
    for (int j = 0; j < nDefenseDice; j++){
        defenseDice[j] = new Die(6);
    }

    //Set up Armor and Strength
    this->armor = 3;
    this->strength = 8;
}

/********************************************************************* 
** Description: attack rolls all the attacker's attack dice and 
returns the value of the roll.
*********************************************************************/
int Medusa::attack(){
    
    int attackRoll = 0;

    //Roll each die in turn, adding the number to the total
    for (int i = 0; i < nAttackDice; i++){
        attackRoll += attackDice[i]->roll();
    }

    //If Medusa rolls a 12, then she uses Glare and automatically kills her opponent.
    if (attackRoll == 12){
        //cout << this->name << " rolled a 12! She uses \"Glare\"!\n";
        attackRoll = 999;
    }

    //Print out the result of the roll.
    //cout << "Attack roll: " << attackRoll << endl;

    return attackRoll;
}

/********************************************************************* 
** Description: rollDefense rolls all the defender's defense dice 
and returns the value of the roll.
*********************************************************************/
int Medusa::rollDefense(){
    int rollSum = 0;

    //Roll each die in turn, adding the number to the total
    for (int i = 0; i < nDefenseDice; i++){
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
int Medusa::defense(int attackRoll, int defenseRoll){
    //Damage is attack roll - defense roll - armor
    int netDamage = attackRoll-(defenseRoll + this->armor);

    //Don't let net damage go below 0
    if (netDamage < 0){
        netDamage = 0;
    }

    //Update strength
    strength -= netDamage;

    //Don't let health go below 0
    if (strength < 0){
        strength = 0;
    }

    return netDamage;
}

/********************************************************************* 
** Description: getCharacterName returns the type of character as a 
string.
*********************************************************************/
string Medusa::getCharacterName(){
    return "Medusa";
}

/********************************************************************* 
** Description: printStats prints the type, name, armor, and strength 
of the character to the terminal.
*********************************************************************/
void Medusa::printStats(){
    cout << "Type: Medusa" << endl;
    cout << "Name: " << name <<endl;
    cout << "Armor: " << armor << endl;
    cout << "Strength: " << strength << endl;
}

/********************************************************************* 
** Description: getName returns the character's name as a string.
*********************************************************************/
string Medusa::getName(){
    return name;
}

/********************************************************************* 
** Description: Destructor deletes the attack and defense dice along 
with their pointers.
*********************************************************************/
Medusa::~Medusa(){
    //Delete attack dice
    for (int i = 0; i < nAttackDice; i++){
        delete attackDice[i];
    }
    //Delete defense dice
    for (int j = 0; j < nDefenseDice; j++){
        delete defenseDice[j];
    }
    delete[] attackDice;
    delete[] defenseDice;
}

void Medusa::recover(){
    int strengthLost = 8-strength;
    strength = strength + (strengthLost/2);
}
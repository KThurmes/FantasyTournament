/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: Harry Potter is an implementation of the Character 
virtual class. If a HarryPotter character dies, it uses "Hogwarts" 
and comes back to life with 20 strength points. The character can 
only use Hogarts once.
*********************************************************************/
#include "HarryPotter.hpp"
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
HarryPotter::HarryPotter(string name){
    this->name = name;

    //Set up the sets of dice
    //Set up attack dice
    nAttackDice = 2;
    attackDice = new Die*[nAttackDice];
    for (int i = 0; i < nAttackDice; i++){
        attackDice[i] = new Die(6);
    }
    //Set up defense dice
    nDefenseDice = 2;
    defenseDice = new Die*[nDefenseDice];
    for (int j = 0; j < nDefenseDice; j++){
        defenseDice[j] = new Die(6);
    }

    //Set up Armor and Strength
    this->armor = 0;
    this->strength = 20;

    //Set flag to false because he hasn't come back to life yet
    this->secondLife = false;
}

/********************************************************************* 
** Description: attack rolls all the attacker's attack dice and 
returns the value of the roll.
*********************************************************************/
int HarryPotter::attack(){

    int attackRoll = 0;

    //Roll each die in turn, adding the number to the total
    for (int i = 0; i < nAttackDice; i++){
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
int HarryPotter::rollDefense(){
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
int HarryPotter::defense(int attackRoll, int defenseRoll){
    //Damage is attack roll - defense roll - armor
    int netDamage = attackRoll-(defenseRoll + this->armor);

    //Don't let net damage go below 0
    if (netDamage < 0){
        netDamage = 0;
    }

    //Update strength
    strength -= netDamage;

    //Don't let health go below 0. If it goes to 0 or less, check if HP has come back to life once already
    if (strength < 1){
        //Check if HP has come back to life once already. If not, bump HP's strength up to 20.
        if (secondLife == false){
            //cout << this-> name << " used \"Hogwarts\"!\n";
            this->strength = 20;
            this->secondLife = true;
        }
        //If HP has already come back to life, HP dies.
        else{
            strength = 0;
            //cout << this-> name << "'s luck has run out!\n";
        }
    }
    
    return netDamage;
}

/********************************************************************* 
** Description: getCharacterName returns the type of character as a 
string.
*********************************************************************/
string HarryPotter::getCharacterName(){
    return "Harry Potter";
}

/********************************************************************* 
** Description: printStats prints the type, name, armor, and strength 
of the character to the terminal.
*********************************************************************/
void HarryPotter::printStats(){
    
    cout << "Type: Harry Potter" << endl;
    cout << "Name: " << name <<endl;
    cout << "Armor: " << armor << endl;
    cout << "Strength: " << strength << endl;
    
}

/********************************************************************* 
** Description: getName returns the character's name as a string.
*********************************************************************/
string HarryPotter::getName(){
    return name;
}

/********************************************************************* 
** Description: Destructor deletes the attack and defense dice along 
with their pointers.
*********************************************************************/
HarryPotter::~HarryPotter(){
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

void HarryPotter::recover(){
    int strengthLost = 10-strength;
    strength = strength + (strengthLost/2);
}
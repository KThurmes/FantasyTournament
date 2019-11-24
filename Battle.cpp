/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: The Battle class sets up and controls a battle 
between two characters. Its data members include two pointers to 
characters and a flag that is set to true when a player has lost. 
It contains methods to control a whole battle (runBattle), run one 
turn (turn), and swap which character is defending and which is 
attacking (swapRoles).
*********************************************************************/
#include "Battle.hpp"
#include <iostream>

using std::cout;
using std::endl;

/********************************************************************* 
** Description: The constructor sets up a battle between two 
characters (inputted to the function with pointers).
*********************************************************************/
Battle::Battle(Character *c1, Character *c2)
{
    attacker = c1;
    defender = c2;
    playerLost = 0;
}

/********************************************************************* 
** Description: runBattle will control the battle until one of the 
characters is out of strength points. Each round consists of each 
character getting a chance to attack and to defend. The function 
takes an int that indicates which nuber round it is.
*********************************************************************/
void Battle::runBattle(int nRound)
{
    //Print out round number
    //cout << "------Round " << nRound << "------" << endl;
    //Attacker attacks; defender defends
    turn();

    //Check if battle is over
    /*     if (playerLost)
    {
        //cout << "------" << defender->getName() << " lost!" << "------" << endl;
    } */

    //If not over, players switch roles and fight again
    if (!playerLost)
    {
        swapRoles();
        turn();
        if (playerLost)
        {
            //cout << defender->getName() << " lost!" << endl;
        }

        //Increment nRound and go again.
        else
        {
            //cout << endl;
            nRound++;
            runBattle(nRound);
        }
    }
}

/********************************************************************* 
** Description: Turn controls a single round within the battle. It 
has the attacker attack and it has the defender defend. It also 
prints out updates to the terminal as it goes.
*********************************************************************/
void Battle::turn()
{

    //Print out type of attacker
    //cout << "Attacker stats:\n";
    //attacker->printStats();
    //cout << "*******************************************\n";

    //Print out defender stats
    //cout<< "Defender stats: "<< endl;
    //defender->printStats();
    //cout << "*******************************************\n";

    //Roll attack
    int attackRoll = attacker->attack();

    //Roll defense
    int defenseRoll = defender->rollDefense();

    //Take damage
    int totalDamage = defender->defense(attackRoll, defenseRoll);

    //Print total inflicted damage
    //cout << "Total inflicted damage: " << totalDamage <<endl;
    if (defender->getStrength() < 1)
    {
        playerLost = true;
    }

    //Print defender's strength
    //cout << "Defender's remaining strength: " << defender->getStrength() << endl ;
}

/********************************************************************* 
** Description: swapRoles switches which character is in the 
"defender" role and which is in the "attacker" role.
*********************************************************************/
void Battle::swapRoles()
{
    Character *temp;
    temp = attacker;
    attacker = defender;
    defender = temp;
}

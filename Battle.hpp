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
#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Character.hpp"

class Battle{
    private:
        Character* attacker;
        Character* defender;
        bool playerLost;
    public:
        Battle(Character*, Character*);
        void turn();
        void swapRoles();
        void runBattle(int);
};

#endif
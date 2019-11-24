/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
** Description: The Menu class allows the player to choose whether to 
play a round, allows the player to choose and name their characters, 
and launches the battle between two characters.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include "getNumberBetween.hpp"
#include "Character.hpp"
#include <string>
#include "Queue.hpp"

class Menu{
    private:
    public:
        void mainMenu();
        void roundSetup();
        Character* createCharacter(int, string);
        Queue* teamSetup(int);
        void tournamentSetup();
};

#endif
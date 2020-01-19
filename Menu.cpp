/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019 (Updated 24 Nov., 2019)
** Description: The Menu class allows the player to choose whether to 
play a round, allows the player to choose and name their characters, 
and launches the battle between two characters.
*********************************************************************/

#include "Menu.hpp"
#include "Vampire.hpp"
#include <iostream>
#include "Battle.hpp"
#include "Barbarian.hpp"
#include "BlueMan.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Character.hpp"
#include <string>
#include "Tournament.hpp"
#include "DoubleLinkedList.hpp"
#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

/********************************************************************* 
** Description: welcome prints a welcome message when the program 
starts.
*********************************************************************/
void Menu::welcome()
{
    cout << endl;
    cout << "*********************************************************************" << endl;
    cout << "WELCOME TO THE FANTASY TOURNAMENT!" << endl
         << endl;
    cout << "Teams of fantasy characters will face off against each other in a \nseries of single-combat battles. Teams get 2 points for a win and -1 \npoint for a loss.\n\nThe tournament ends when one team runs out of characters. The team \nwith the most points is the winner!\n";
    cout << "*********************************************************************" << endl;
    mainMenu();
}

/********************************************************************* 
** Description: mainMenu is the first menu a player will see when 
they start the program. It allows the player to choose whether to 
start a new round or quit. These options are displayed after a battle 
has been played, as well.
*********************************************************************/
void Menu::mainMenu()
{
    cout << "\nWhich would you like to do?\n";
    cout << "1. Play a tournament\n";
    cout << "2. Quit\n";
    int selection = getNumberBetween(1, 2);
    if (selection == 1)
    {
        cout << "Hoorah! Starting a new tournament!\n";
        Tournament tourney;
        tourney.tournamentSetup();
        mainMenu();
    }
    else
    {
        cout << "Thanks for playing!\n";
    }
}
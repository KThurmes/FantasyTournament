/********************************************************************* 
** Author: Katheen Thurmes
** Date: 2 Nov., 2019
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

using std::cout;
using std::endl;
using std::string;
using std::cin;

/********************************************************************* 
** Description: mainMenu is the first menu a player will see when 
they start the program. It allows the player to choose whether to 
start a new round or quit. These options are displayed after a battle 
has been played, as well.
*********************************************************************/
void Menu::mainMenu(){
    cout << "\nWhich would you like to do?\n";
    cout << "1. Play a single round\n";
    cout << "2. Play a tournament\n";
    cout << "3. Quit\n";
    int selection = getNumberBetween(1,2);
    if  (selection == 1){
        roundSetup();
        //Restart after the battle
        mainMenu();
    }

    else if( selection == 2){
        cout << "Hoorah! Starting a new tournament!\n";
    }
    //Else, quit
}

/********************************************************************* 
** Description: roundSetup will create a new round and will 
automatically start playing it. It allows the player to choose what 
types of characters they want to do battle against each other and 
it allows them to name the characters.
*********************************************************************/
void Menu::roundSetup(){

    cout << "\nCharacter types: \n";
    cout << "1. Vampire\n";
    cout << "2. Barbarian\n";
    cout << "3. Blue Man\n";
    cout << "4. Medusa\n";
    cout << "5. Harry Potter\n";

    cout << "Please select a type for Character 1.\n";
    int selection1 = getNumberBetween(1, 5);
    cout << "What would you like Character 1 to be called?\n";
    string name;
    cin >> name;
    Character* c1 = createCharacter(selection1, name);

    cout << "Please select a type for Character 2.\n";
    int selection2 = getNumberBetween(1, 5);
    cout << "What would you like Character 2 to be called?\n";
    cin >> name;
    Character* c2 = createCharacter(selection2, name);

    Battle round1(c1, c2);
    round1.runBattle(1);
    delete c1;
    delete c2;
}


/********************************************************************* 
** Description: This is a helper function that will take the player's 
selection from roundSetup and create the coordinating character type. 
That character will have the name that the player inputted in 
roundSetup, as well. This function returns a pointer to the newly 
created character.
*********************************************************************/
Character* Menu::createCharacter(int charType, string name){
    Character* character;
    switch (charType){
        case 1:
            character = new Vampire(name);
            break;
        case 2: 
            character = new Barbarian(name);
            break;
        case 3:
            character = new BlueMan(name);
            break;
        case 4:
            character = new Medusa(name);
            break;
        case 5:
            character = new HarryPotter(name);
            break;
    }
    return character;
}
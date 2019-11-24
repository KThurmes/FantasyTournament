#include "Tournament.hpp"
#include "Battle.hpp"
#include <iostream>
#include "getNumberBetween.hpp"
#include "Node.hpp"
#include "DoubleLinkedList.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMan.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

using std::cin;
using std::cout;
using std::endl;

Tournament::Tournament() {}

void Tournament::deleteTournament()
{
    team1.deleteDLList();
    team2.deleteDLList();
    losers.deleteDLList();
}

void Tournament::runRound(int n)
{

    Node *nodeOne = team1.popFront();
    Node *nodeTwo = team2.popFront();
    Character *cOne = nodeOne->getCharacter();
    Character *cTwo = nodeTwo->getCharacter();

    cout << "Round " << n << ": "
         << "Team 1's " << cOne->getName()
         << " vs. "
         << "Team 2's " << cTwo->getName() << endl;

    Battle battl(cOne, cTwo);

    battl.runBattle(1);
    //cout << "Here1!\n";

    if (cOne->getStrength() == 0)
    {
        cTwo->recover();
        losers.addToBack(nodeOne);
        team2.addToBack(nodeTwo);
        cout << cTwo->getName() << " won!\n";
    }

    else
    {
        cOne->recover();
        losers.addToBack(nodeTwo);
        team1.addToBack(nodeOne);
        cout << cOne->getName() << " won!\n";
    }
    //cout << "Here2!\n";

    cout << "Here's who is in the loser queue: ";
    losers.traverse();
    cout << endl;
}

void Tournament::runTournament()
{
    int i = 1;
    while (!team1.isEmpty() && !team2.isEmpty())
    {
        runRound(i);
        ++i;
    }

    if (team1.isEmpty())
    {
        cout << "Team 2 won!\n";
        team2.deleteDLList();
        losers.deleteDLList();
    }
    else
    {
        cout << "Team 1 won!\n";
        team1.deleteDLList();
        losers.deleteDLList();
    }
}

void Tournament::printLosers()
{
    losers.traverse();
}

void Tournament::teamSetup(int teamN)
{
    cout << "How many players on Team " << teamN << "?\n";
    int players = getNumberBetween(1, 500);

    cout << "\nCharacter types: \n";
    cout << "1. Vampire\n";
    cout << "2. Barbarian\n";
    cout << "3. Blue Man\n";
    cout << "4. Medusa\n";
    cout << "5. Harry Potter\n";

    string name;
    int selection;

    for (int i = 0; i < players; ++i)
    {
        cout << "Please select a type for Character " << i + 1 << ".\n";
        selection = getNumberBetween(1, 5);
        cout << "What would you like Character " << i + 1 << " to be called?\n";
        cin >> name;
        Character *c = createCharacter(selection, name);
        if (teamN == 1)
        {
            team1.addToBack(c);
        }
        else
        {
            team2.addToBack(c);
        }
    }
}

/********************************************************************* 
** Description: This is a helper function that will take the player's 
selection from teamSetup and create the coordinating character type. 
That character will have the name that the player inputted in 
roundSetup, as well. This function returns a pointer to the newly 
created character.
*********************************************************************/
Character *Tournament::createCharacter(int charType, string name)
{
    Character *character;
    switch (charType)
    {
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

void Tournament::tournamentSetup()
{
    teamSetup(1);
    teamSetup(2);
    runTournament();
    deleteTournament();
}

void Tournament::autoSetup()
{
    Character *vlad = new Vampire("Vampy1");
    //Node* node1 = new Node(vlad);
    Character *barbie = new Barbarian("Barb1");
    Character *smurf = new BlueMan("Smurf1");
    Character *stoney = new Medusa("SnakeHair1");
    Character *hp = new HarryPotter("Harry1");

    team1.addToBack(vlad);
    team1.addToBack(barbie);
    team1.addToBack(smurf);
    team1.addToBack(stoney);
    team1.addToBack(hp);

    Character *vlad2 = new Vampire("Vampy2");
    //Node* node2 = new Node(vlad2);
    Character *barbie2 = new Barbarian("Barb2");
    Character *smurf2 = new BlueMan("Smurf2");
    Character *stoney2 = new Medusa("SnakeHair2");
    Character *hp2 = new HarryPotter("Harry2");

    team2.addToBack(vlad2);
    team2.addToBack(barbie2);
    team2.addToBack(smurf2);
    team2.addToBack(stoney2);
    team2.addToBack(hp2);

    runTournament();
    this->deleteTournament();
}
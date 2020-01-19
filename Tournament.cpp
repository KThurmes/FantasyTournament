/********************************************************************* 
** Author: Katheen Thurmes
** Date: 24 Nov., 2019
** Description: The Tournament class drives the fantasy character 
team tournament. It has driver functions for coordinating the running 
of the whole tournament, for running a single round, for setting up 
each of the teams, and deleting the teams. It contains three double 
linked lists as data members: a list of remaining players on team 1, 
a list of remaining players on team 2, and a list of players that 
have lost a round, the loser list.
*********************************************************************/
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

Tournament::Tournament()
{
    team1Score = 0;
    team2Score = 0;
}

/********************************************************************* 
** Description: deleteTournament deletes all three of the lists of 
characters.
*********************************************************************/
void Tournament::deleteTournament()
{
    team1.deleteDLList();
    team2.deleteDLList();
    losers.deleteDLList();
}

/********************************************************************* 
** Description: runRound creates a Battle object using the first 
characters in each team's queue. It runs the battle and puts the 
losing character in the loser list and the winner goes to the back 
of their team's list after recovering. It takes one input value, 
nRound, which describes which number round the tournament is on.
*********************************************************************/
void Tournament::runRound(int nRound)
{

    Node *nodeOne = team1.popFront();
    Node *nodeTwo = team2.popFront();
    Character *cOne = nodeOne->getCharacter();
    Character *cTwo = nodeTwo->getCharacter();
    cout << "\n*********************** Round " << nRound << " *****************************************" << endl;
    cout << "Team 1's " << cOne->getName()
         << " vs. "
         << "Team 2's " << cTwo->getName() << endl;

    Battle battl(cOne, cTwo);

    battl.runBattle(1);

    if (cOne->getStrength() == 0)
    {
        cTwo->recover();
        losers.addToBack(nodeOne);
        team2.addToBack(nodeTwo);
        cout << cTwo->getName() << " won!\n";
        //Add two points to the winning team's final score
        team2Score += 2;
        //Subtract one point from the losing team's score
        team1Score -= 1;
    }

    else
    {
        cOne->recover();
        losers.addToBack(nodeTwo);
        team1.addToBack(nodeOne);
        cout << cOne->getName() << " won!\n";
        //Add two points to the winning team's final score
        team1Score += 2;
        //Subtract one point from the losing team's score
        team2Score -= 1;
    }
    cout << "*************************************************************************" << endl
         << endl;
}

/********************************************************************* 
** Description: runTournament checks to see if either of the teams 
have run out of characters to fight. If not, it calls runRound to run 
the next round. If so, it anounces the winner and deletes the 
remaining lists.
*********************************************************************/
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
        cout << "Team 1 is out of characters!\n";
    }
    else
    {
        cout << "Team 2 is out of characters!\n";
    }
}

/********************************************************************* 
** Description: printLosers prints out the characters in the losers 
list.
*********************************************************************/
void Tournament::printLosers()
{
    losers.traverseReverse();
}

/********************************************************************* 
** Description: teamSetup allows the user to specify how many 
characters are on a team, what types they are, and what their names 
are. It takes one input, int teamN, which represents the team number.
*********************************************************************/
void Tournament::teamSetup(int teamN)
{
    cout << "\nHow many players on Team " << teamN << "?\n";
    int players = getNumberBetween(1, 500);

    cout << "\nCharacter types: \n";
    cout << "1. Vampire\n";
    cout << "2. Barbarian\n";
    cout << "3. Blue Man\n";
    cout << "4. Medusa\n";
    cout << "5. Harry Potter\n";
    cout << endl;

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

/********************************************************************* 
** Description: tournamentSetup drives the course of the tournament 
by calling the team setup function, running the tournament, and 
deleting the tournament in the end.
*********************************************************************/
void Tournament::tournamentSetup()
{
    teamSetup(1);
    teamSetup(2);
    runTournament();
    tournamentEnd();
    this->deleteTournament();
}

void Tournament::tournamentEnd()
{
    cout << endl;
    cout << "FINAL SCORE: \n";
    cout << "Team 1: " << team1Score << " points\n";
    cout << "Team 2: " << team2Score << " points\n";
    if (team1Score > team2Score)
    {
        cout << "Team 1 won!\n";
    }
    else if (team1Score < team2Score)
    {
        cout << "Team 2 won!\n";
    }
    else
    {
        cout << "The tournament was a tie!\n";
    }
    cout << endl;
    cout << "Would you like to see the list of losing characters?\n";
    cout << "1. Yes\n";
    cout << "2. No\n";
    int selection = getNumberBetween(1, 2);
    if (selection == 1)
    {
        cout << "Here's who is in the loser queue: ";
        printLosers();
        cout << endl
             << "*********************************************************************" << endl;
    }
}

/********************************************************************* 
** Description: autoSetup is a function used in the debugging phase 
to skip the step of setting up the two teams. It creates two teams 
with one of each of the five characters on it, runs the tournament, 
and then deletes the tournament.
*********************************************************************/
void Tournament::autoSetup()
{
    Character *vlad = new Vampire("Vampy1");
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

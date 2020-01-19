#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "DoubleLinkedList.hpp"

class Tournament
{
private:
    DLList team1;
    DLList team2;
    DLList losers;
    int team1Score;
    int team2Score;

public:
    Tournament();
    void deleteTournament();
    void runTournament();
    void printLosers();
    void runRound(int);
    void teamSetup(int);
    Character *createCharacter(int charType, string name);
    void tournamentSetup();
    void autoSetup();
    void tournamentEnd();
};

#endif
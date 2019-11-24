/********************************************************************* 
** Title: Die
** Author: Katheen Thurmes
** Date: 19 Oct., 2019
** Description: Die is a class that describes a gaming die. It can 
have any number of faces (N) and it contains a roll() function that 
returns a random value between 1 and its number of faces. It also 
contains a constructor, a destructor, and getter and setter 
functions.

The roll() function is virtual because a child class, LoadedDie, 
overloads the function so that it can roll a much higher average 
value.
*********************************************************************/ 

#include "Die.hpp"
#include <stdlib.h>
#include <iostream>
using std::cout;

void Die::setN(int n){
    N = n;
}

int Die::roll(){
    //Get random number between 1 and N
    int rollResult = rand() % (N) + 1;
    return rollResult;
}

int Die::getN(){
    return N;
}
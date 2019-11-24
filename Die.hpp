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
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    protected:
        int N; //Number of sides of the die
    public:
        Die(int n = 6){
            N = n;
        }
        virtual int roll(); //Virtual function made with guidence from https://www.geeksforgeeks.org/virtual-function-cpp/ Accessed 10.19.19
        int getN();
        void setN(int);
        virtual ~Die(){}; //Virtual destructor made with guidence from https://www.geeksforgeeks.org/virtual-destructor/ Accessed 10.19.19
};

#endif

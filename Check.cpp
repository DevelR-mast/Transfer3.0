#include "Check.h"

check::check(): balance{0}
{
    numbercheck = random()%10000 + 1;
}

void check::increasebalance(int Sum)
{
    balance += Sum;
}

void check::decreasebalance(int Sum)
{
    if(Sum > balance) { throw error {"decreasebalance"};}
    balance -=Sum;
}

int check::returnbalance() const
{
    return balance;
}

int check::returnnumbercheck() const
{
    return numbercheck;
}
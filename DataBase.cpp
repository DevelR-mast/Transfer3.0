#include "DataBase.h"

database::database() {}

database::~database() {}

int database::addcheck()
{
    check *ptr = new check;
    cont_check[ptr->returnnumbercheck()] = ptr;
    return ptr->returnnumbercheck();
}

void database::addaccount(std::string Name, std::string GrandName, std::string NumberPhone, std::string Login, std::string Password)
{
    account *ptr = new account{Name, GrandName, NumberPhone, Login, Password};
    cont_account.push_back(ptr);
}

void database::depositintocheck(int NumberCheck, int Sum)
{
    cont_check.at(NumberCheck)->increasebalance(Sum);
    cont_historytransfer[NumberCheck].push_back("deposit on sum: "+ std::to_string(Sum));
}

void database::withdrawfromcheck(int NumberCheck, int Sum)
{
    cont_check.at(NumberCheck)->decreasebalance(Sum);
    cont_historytransfer[NumberCheck].push_back("withdraw on sum: " + std::to_string(Sum));
}

void database::transfertocheck(int NumberCheckSender, int NumberCheckRecived, int Sum)
{
    cont_check.at(NumberCheckSender)->decreasebalance(Sum);
    cont_check.at(NumberCheckRecived)->increasebalance(Sum);
    cont_historytransfer[NumberCheckSender].push_back("transfer(-) on sum: "+ std::to_string(Sum));
    cont_historytransfer[NumberCheckRecived].push_back("transfer(+) on sum: " + std::to_string(Sum));
}

int database::returnbalance(int NumberCheck)
{
    return cont_check.at(NumberCheck)->returnbalance();
}
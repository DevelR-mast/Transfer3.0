#include "Account.h"

account::account(std::string Name, std::string GrandName, std::string NumberPhone, std::string Login, std::string Password)
: name{Name}, grandname{GrandName}, numberphone{NumberPhone}, login{Login}, password{Password} 
{
    std::cout<<"Account from "<<Name<<" "<<GrandName<<" created"<<std::endl;
}
account::~account() {}

std::string account::autorization(std::string Login, std::string Password)
{
    if(Login == login&& Password == password)
    {
        std::string temp {};

        temp += name; temp += "/";
        temp += grandname; temp += "/";
        temp += login; temp += "/";
        temp += password; temp += "/";
        temp += numberphone; temp += "/";
        temp += std::to_string(numbercheck); temp += "/";
        temp += std::to_string(DataBase.returnbalance(numbercheck));

        return temp;
    }
    else
    {
        return "f";
    }
}
#pragma once
#include <vector>
#include <string>
#include <map>

#include "Account.h"
#include "Check.h"

class database
{
    private:
        std::vector<account*> cont_account;
        std::map<int, check*> cont_check;
        std::map<int, std::vector<std::string> > cont_historytransfer;
    public:
        database();
        ~database();
    public:
        int addcheck();
        void addaccount(std::string, std::string, std::string, std::string, std::string);
        void depositintocheck(int, int);
        void withdrawfromcheck(int, int);
        void transfertocheck(int, int, int);
        int returnbalance(int);
        std::vector<std::string> returnhistorytransfer(int);
    public:
        bool authorization(std::string, std::string);
};
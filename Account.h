#pragma once

#include "Error.h"
#include "Check.h"
#include "Kernel.h"
#include "Server.h"

class account
{
    private:
        std::string name, grandname;
        //std::string serias, number;
        std::string login, password;
        std::string numberphone;
        int numbercheck;
    public:
        account(std::string, std::string, std::string, std::string, std::string);
        ~account();
    public:
        void createcheck();                             //From client
        void deletecheck();                             //From client
        void replenishbalance(int);                     //From client
        void withdrawbalance(int);                      //From client
        void transfermoney(int, int);                   //From client
        void showbalance();                             //From client
        void showhistorytransfer();                     //From client
    public:
        std::string autorization(std::string, std::string);
};
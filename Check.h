#pragma once

#include "Error.h"

class check
{
    private:
        int numbercheck, balance;
    public:
        check();
        ~check();
    public:
        void increasebalance(int);
        void decreasebalance(int);
        int returnbalance() const;
        int returnnumbercheck() const;
};
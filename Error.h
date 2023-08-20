#pragma once

#include <iostream>
#include <string>

class error
{
    public:
        std::string str;
    public:
        error(std::string);
        ~error();
    public:
        void displaymessage() const;
};
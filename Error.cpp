#include "Error.h"

error::error(std::string message):str{message} {}

error::~error() {}

void error::displaymessage() const
{
    std::cout<<"Error: "<<str<<std::endl;
}
#pragma once

#include "Error.h"
#include "Server.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#include <unistd.h>

class kernel
{
    private:
        int sock, newsock;
        struct sockaddr_in addr;
    private:
        void control(int);
        void connectionhandler(int);
        void listening();
        void sendmessage(int, std::string);
    public:
        kernel();
        ~kernel();
    public:
        void start();
};
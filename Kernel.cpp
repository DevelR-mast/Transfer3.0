#include "Kernel.h"

//Dont release 2 and 7 message

kernel::kernel() {}

kernel::~kernel() {}

void kernel::control(int number)
{
    if(number <0) { exit(0); }
}

void kernel::start()
{
    sock = socket(AF_UNSPEC, SOCK_STREAM, 0);
    control(sock);

    addr.sin_family = AF_UNSPEC;
    addr.sin_port = htons(3406);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    listening();    
}

void kernel::listening()
{
    control(bind(sock, (struct sockaddr*)&addr, sizeof(addr)));
    control(listen(sock, 5));

    while(true)
    {
        sleep(2);
        newsock = accept(sock, NULL, NULL);
        if(newsock <= 0)
        {
            continue;
        }
        connectionhandler(newsock);
        
    }
}

void kernel::connectionhandler(int NewSock)
{
    char buff[30];

    recv(NewSock, buff, sizeof(buff), 0);

    switch(buff[0])
    {
        case 1:
        {
            int result = DataBase.addcheck();
            std::string str = std::to_string(result);
            sendmessage(newsock, str);
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            std::string str {};
            short index = 2;
            while(buff[index] != '/')
            {
                str += buff[index];
                ++index;
            }
            int check = std::stoi(str);
            ++index;
            while (buff[index])
            {
                str += buff[index];
                ++index;
            }
            int sum = std::stoi(str);

            DataBase.depositintocheck(check, sum);
            str = "t/";
            str += std::to_string(DataBase.returnbalance(check));
            sendmessage(newsock, str);
            break;
        }
        case 4:
        {
            std::string str {};
            short index = 2;
            while(buff[index] != '/')
            {
                str += buff[index];
                ++index;
            }
            int check = std::stoi(str);
            ++index;
            while (buff[index])
            {
                str += buff[index];
                ++index;
            }
            int sum = std::stoi(str);

            try
            {
                DataBase.withdrawfromcheck(check, sum);
                str = "t/";
                str += std::to_string(DataBase.returnbalance(check));
                sendmessage(newsock, str);
            }
            catch(error Error)
            {
                Error.displaymessage();
                sendmessage(newsock, "f");
            }
            break;
        }
        case 5:
        {
            std::string str {};
            short index = 2;
            while(buff[index] != '/')
            {
                str += buff[index];
                ++index;
            }
            int checksender = std::stoi(str);
            ++index;
            while(buff[index] != '/')
            {
                str += buff[index];
                ++index;
            }
            int checkreciver = std::stoi(str);
            while (buff[index])
            {
                str += buff[index];
                ++index;
            }
            int sum = std::stoi(str);
            ++index;

            try
            {
                DataBase.withdrawfromcheck(checksender, sum);
                DataBase.depositintocheck(checkreciver, sum);
                str = "t/";
                str += std::to_string(DataBase.returnbalance(checksender));
                sendmessage(newsock, str);
            }
            catch(error Error)
            {
                Error.displaymessage();
                sendmessage(newsock, "f");
            }
            break;
        }
        case 6:
        {
            std::string str {};
            short index = 2;
            while(buff[index])
            {
                str += buff[index];
                ++index;
            }
            int checksender = std::stoi(str);

            checksender = DataBase.returnbalance(checksender);
            str = std::to_string(checksender);
            sendmessage(newsock, str);
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {
            std::string strlog {};
            short index = 2;
            while(buff[index] != '/')
            {
                strlog += buff[index];
                ++index;
            }
            std::string strpass {};
            ++index;
            while(buff[index])
            {
                strpass += buff[index];
                ++index;
            }

            if(DataBase.authorization(strlog, strpass))                 // Dont realese
            {

            }
            else
            {
                sendmessage(newsock, "f");
            }
            break;
        }
        default:
        {
            std::cout<<"Allowed command"<<std::endl;
            sendmessage(newsock, "Allowed command");
            break;
        }
    }
}

void kernel::sendmessage(int Sock, std::string Message)
{
    send(Sock, reinterpret_cast<char*>(&Message), Message.size(), 0);
}
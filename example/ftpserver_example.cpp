// ftpserver_example.cpp : Defines the entry point for the console application.
//

#include "ConcreteFtpServer.h"
#include <iostream>


int main()
{

	std::cout << "FTP Server running. Press any key for stopping..." << std::endl;;
	
    mde::FTPServer ftpServer(12345);
    try
    {
        ftpServer.start();
    }
    catch (...)
    {
        std::cout << "Unknown error occured" << std::endl;
    }

	std::cin.ignore();
	std::cout << "FTP Server stopped" << std::endl;;
	return 0;
}

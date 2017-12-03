// ftpserver_example.cpp : Defines the entry point for the console application.
//

#include "ConcreteFtpServer.h"
#include <iostream>


int main()
{

	std::cout << "FTP Server running. Press any key for stopping..." << std::endl;;
	
    mde::FTPServer ftpServer(12345);
    ftpServer.start();

	std::cin.ignore();
	std::cout << "FTP Server stopped" << std::endl;;
	return 0;
}

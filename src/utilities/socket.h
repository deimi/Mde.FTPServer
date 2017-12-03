#ifndef MDE_SOCKET_H
#define MDE_SOCKET_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

namespace mde { namespace ftp_utilities {

#define BACKLOG 20
#define MAXRECV	2048

    // TODO Make interface for Socket
    // TODO Implement different Sockets for Win/Linux
    class Socket {
    private:
        int _sockfd;
        struct sockaddr_in _addr;
        bool is_valid();

    public:
        Socket();
        ~Socket();
        bool create();
        bool bind(int);
        bool connect(int, int);
        bool listen();
        bool accept(Socket&);
        int send(std::string);
        int recv(std::string&);
        bool close();
        int fd();
        void fd(int);
        int port();
        std::string host();
    };

} // namespace ftp_utilities
} // namespace mde

#endif // MDE_SOCKET_H

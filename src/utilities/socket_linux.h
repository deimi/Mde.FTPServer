// Linux socket declaration

#ifndef MDE_SOCKET_LINUX_H
#define MDE_SOCKET_LINUX_H

#include <cstdio>
#include <cstring>
#include <cstdint>

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include "i_socket.h"

namespace mde { namespace ftp_utilities {

    // TODO Implement different Sockets for Win/Linux
    class SocketLinux : public ISocket {
    private:
        int _sockfd;
        struct sockaddr_in _addr;
        bool is_valid();

        static const uint32_t kMaxBufferSize = 2048;

    public:
        SocketLinux();
        ~SocketLinux();
        bool create();
        bool bind(int);
        bool connect(int, int);
        bool listen();
        bool accept(ISocket&);
        int send(std::string);
        int recv(std::string&);
        bool close();
        int fd();
        void fd(int);
        int port();
        std::string host();
        uint32_t getMaxBufferSize();
    };

} // namespace ftp_utilities
} // namespace mde

#endif // MDE_SOCKET_LINUX_H

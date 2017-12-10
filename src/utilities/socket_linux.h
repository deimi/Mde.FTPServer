// Linux socket declaration

#ifndef MDE_SOCKET_LINUX_H
#define MDE_SOCKET_LINUX_H

// compile only for linux
#ifdef __linux__

#include <cstdint>
#include <string>

#include <arpa/inet.h>

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

#endif // __linux__

#endif // MDE_SOCKET_LINUX_H

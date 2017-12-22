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

    class SocketLinux : public ISocket {
    private:
        int32_t _sockfd;
        struct sockaddr_in _addr;
        bool is_valid();

        static const uint32_t kMaxBufferSize = 2048;

    public:
        SocketLinux();
        ~SocketLinux();
        bool create();
        bool bind(int32_t);
        bool connect(int32_t, int32_t);
        bool listen();
        bool accept(ISocket&);
        int32_t send(std::string);
        int32_t recv(std::string&);
        bool close();
        int32_t fd();
        void fd(int32_t);
        int32_t port();
        std::string host();
        uint32_t getMaxBufferSize();
    };

} // namespace ftp_utilities
} // namespace mde

#endif // __linux__

#endif // MDE_SOCKET_LINUX_H

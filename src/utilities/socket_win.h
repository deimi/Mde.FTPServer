// Windows socket declaration

#ifndef MDE_SOCKET_WIN_H
#define MDE_SOCKET_WIN_H

// compile only for windows
#ifdef _WIN32

#include <cstdint>
#include <string>

#include "WinSock2.h"

#include "i_socket.h"

namespace mde { namespace ftp_utilities {

    class SocketWin : public ISocket {
    private:
        int _sockfd;
        struct sockaddr_in _addr;
        bool is_valid();

        static const uint32_t kMaxBufferSize = 2048;

    public:
        SocketWin();
        ~SocketWin();
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

#endif // _WIN32

#endif // MDE_SOCKET_WIN_H

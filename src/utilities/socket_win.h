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
        int32_t _sockfd;
        struct sockaddr_in _addr;
        bool is_valid();

        static const uint32_t kMaxBufferSize = 2048;

    public:
        SocketWin();
        ~SocketWin();
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

#endif // _WIN32

#endif // MDE_SOCKET_WIN_H

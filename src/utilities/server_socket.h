#ifndef MDE_SERVERSOCKET_CLASS
#define MDE_SERVERSOCKET_CLASS

#include "socket.h"
#include "socket_exception.h"

namespace mde { namespace ftp_utilities {

    class ServerSocket : private Socket {
    public:
        ServerSocket();
        ServerSocket(int port);
        ~ServerSocket();
        ServerSocket& operator <<(std::string&);
        ServerSocket& operator >>(std::string&);
        void accept(ServerSocket&);
        void close();
        int fd();
        int port();
        std::string host();
    };

} // namespace ftp_utilities
} // namespace mde

#endif // MDE_SERVERSOCKET_CLASS

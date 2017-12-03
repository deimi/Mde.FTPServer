#ifndef MDE_CLIENT_SOCKET_H
#define MDE_CLIENT_SOCKET_H

#include "socket.h"
#include "socket_exception.h"

namespace mde { namespace ftp_utilities {

    class ClientSocket : private Socket {
    public:
        ClientSocket();
        ClientSocket(int, int);
        ClientSocket(std::string, int);
        ~ClientSocket();
        ClientSocket& operator <<(std::string&);
        ClientSocket& operator >>(std::string&);
        void close();
        int fd();
    };

} // namespace 
} // namespace mde

#endif // MDE_CLIENT_SOCKeT_H

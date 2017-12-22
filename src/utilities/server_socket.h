#ifndef MDE_SERVERSOCKET_CLASS
#define MDE_SERVERSOCKET_CLASS

#include <cstdint>

#include <memory>

#include "i_socket.h"
#include "socket_exception.h"

namespace mde { namespace ftp_utilities {

    class ServerSocket {
    public:
        ServerSocket();
        ServerSocket(int32_t port);
        ~ServerSocket();
        ServerSocket& operator <<(std::string&);
        ServerSocket& operator >>(std::string&);
        void accept(ServerSocket&);
        void close();
        int32_t fd();
        int32_t port();
        std::string host();
        uint32_t getMaxBufferSize();

    private:
        std::shared_ptr<ISocket> socket_;
    };

} // namespace ftp_utilities
} // namespace mde

#endif // MDE_SERVERSOCKET_CLASS

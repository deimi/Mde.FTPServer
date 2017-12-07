#ifndef MDE_I_SOCKET_CLASS
#define MDE_I_SOCKET_CLASS

#include <cstdint>

#include <string>

namespace mde { namespace ftp_utilities {
    
    class ISocket {
    public:
        virtual bool create() = 0;
        virtual bool bind(int) = 0;
        virtual bool connect(int, int) = 0;
        virtual bool listen() = 0;
        virtual bool accept(ISocket&) = 0;
        virtual int send(std::string) = 0;
        virtual int recv(std::string&) = 0;
        virtual bool close() = 0;
        virtual int fd() = 0;
        virtual void fd(int) = 0;
        virtual int port() = 0;
        virtual std::string host() = 0;
        virtual uint32_t getMaxBufferSize() = 0;
    };
    
} // namespace ftp_utilities
} // namespace mde

#endif // MDE_I_SOCKET_CLASS
// Linux socket class file which provides wrapper functions to socket functions. 

// compile only for linux
#ifdef __linux__

#include <cstring>

#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include "socket_linux.h"

#define BACKLOG 20

namespace mde { namespace ftp_utilities {

    //Constructor function which intializes _addr to 0 and sets _sockfd to -1
    SocketLinux::SocketLinux() {
        memset(&_addr, 0, sizeof _addr);
        _sockfd = -1;
    }

    //Destructor function
    SocketLinux::~SocketLinux() {
        if (is_valid()) {
            close();
        }
    }

    //Checks for a valid _sockfd i.e != -1
    bool SocketLinux::is_valid() {
        return _sockfd != -1;
    }

    //Return the _sockfd
    int32_t SocketLinux::fd() {
        return _sockfd;
    }

    int32_t SocketLinux::port() {
        struct sockaddr_in local_address;
        socklen_t address_length = sizeof(local_address);
        getsockname(_sockfd, (struct sockaddr*)&local_address, &address_length);
        return ntohs(local_address.sin_port);
    }

    std::string SocketLinux::host() {
        struct sockaddr_in local_address;
        socklen_t address_length = sizeof(local_address);
        getsockname(_sockfd, (struct sockaddr*)&local_address, &address_length);
        return std::string(inet_ntoa(local_address.sin_addr));
    }

    //Allows to set _sockfd
    void SocketLinux::fd(int32_t _fd) {
        _sockfd = _fd;
    }

    //Wrapper function for socket(int32_t domain, int32_t type, int32_t protocol);
    bool SocketLinux::create() {
        _sockfd = socket(PF_INET, SOCK_STREAM, 0);

        if (!is_valid()) {
            return false;
        }

        int32_t yes = 1;

        if (setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int32_t)) == -1) {
            return false;
        }

        return true;
    }

    //Wrapper function for bind(int32_t sockfd, struct sockaddr *my_addr, socklen_t addrlen);
    bool SocketLinux::bind(int32_t port) {
        if (!is_valid()) {
            return false;
        }

        _addr.sin_family = AF_INET;
        _addr.sin_port = htons(port);
        memset(_addr.sin_zero, '\0', sizeof _addr.sin_zero);

        if (::bind(_sockfd, (struct sockaddr *)&_addr, sizeof(_addr)) == -1) {
            return false;
        }

        return true;
    }

    //Wrapper function for connect(int32_t sockfd, const struct sockaddr *serv_addr,socklen_t addrlen);
    bool SocketLinux::connect(int32_t ip, int32_t port) {
        if (!is_valid()) {
            return false;
        }

        _addr.sin_family = AF_INET;
        _addr.sin_port = htons(port);
        _addr.sin_addr.s_addr = ip;

        if (::connect(_sockfd, (sockaddr *)&_addr, sizeof(_addr)) == -1) {
            return false;
        }

        return true;
    }

    //Wrapper function for listen(int32_t s, int32_t backlog);
    bool SocketLinux::listen() {
        if (!is_valid()) {
            return false;
        }

        if (::listen(_sockfd, BACKLOG) == -1) {
            return false;
        }

        return true;
    }

    //Wrapper function for accept(int32_t s, struct sockaddr *addr, socklen_t *addrlen);
    bool SocketLinux::accept(ISocket& child_socket) {
        if (!is_valid()) {
            return false;
        }

        int32_t addr_size = sizeof(_addr);
        int32_t temp_fd = ::accept(_sockfd, (struct sockaddr *)&_addr, (socklen_t *)&addr_size);
        if (temp_fd == -1) {
            return false;
        }

        child_socket.fd(temp_fd);

        return true;
    }

    //Wrapper function for send(int32_t s, const void *buf, size_t len, int32_t flags);
    int32_t SocketLinux::send(std::string msg) {
        if (!is_valid()) {
            return -1;
        }

        return ::send(_sockfd, msg.c_str(), msg.length(), 0); //Set flags to MSG_SIGNAL to IGNORE Broken Pipe Errors.
    }

    //Wrapper function for recv(int32_t s, void *buf, size_t len, int32_t flags);
    int32_t SocketLinux::recv(std::string& s) {
        if (!is_valid()) {
            return -1;
        }

        int8_t buffer[kMaxBufferSize + 5];
        int32_t status =::recv(_sockfd, buffer, kMaxBufferSize, 0);

        if (status > 0) {
            s.assign(buffer, status);
        }

        return status;
    }

    //Wrapper function for close(int32_t s);
    bool SocketLinux::close() {
        if (!is_valid()) {
            return true;
        }

        if (::close(_sockfd) == -1) {
            return false;
        }

        return true;
    }

    uint32_t SocketLinux::getMaxBufferSize() {
        return kMaxBufferSize;
    }

} // namespace ftp_utilities
} // namespace mde

#endif // __linux__ 
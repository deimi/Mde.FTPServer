// Class file of Server Socket 

#include "server_socket.h"
#include "utility.h"
#include "socket_linux.h"

namespace mde { namespace ftp_utilities {

    // TODO move general server socket functions to Server, so it is not double implemented by Server and Client Class
    //Constructor function to create a socket.
    ServerSocket::ServerSocket() {
        socket_ = std::make_shared<SocketLinux>();
        if (false == socket_->create()) {
            throw SocketException(strerror(errno));
        }

    }

    //Constructor function to create, bind and listen a socket on a particular PORT
    ServerSocket::ServerSocket(int port) : ServerSocket() {
        if (false == socket_->bind(port)) {
            throw SocketException(strerror(errno));
        }

        if (false == socket_->listen()) {
            throw SocketException(strerror(errno));
        }
    }

    ServerSocket::~ServerSocket() {

    }

    //Function to send data from socket 
    ServerSocket& ServerSocket::operator <<(std::string& s) {
        if (-1 == socket_->send(s)) {
            throw SocketException(strerror(errno));
        }
        return *this;
    }

    //Function to recv data from socket
    ServerSocket& ServerSocket::operator >>(std::string& s) {
        if (-1 == socket_->recv(s)) {
            throw SocketException(strerror(errno));
        }
        return *this;
    }

    //Fuction to return the FD of the socket.
    int ServerSocket::fd() {
        return socket_->fd();
    }

    //Fuction to return the port of the socket.
    int ServerSocket::port() {
        return socket_->port();
    }

    //Fuction to return the host of the socket.
    std::string ServerSocket::host() {
        return socket_->host();
    }

    // Function to accept the incoming socket connection
    void ServerSocket::accept(ServerSocket& aSocket) {
        if (false == socket_->accept(*(aSocket.socket_))) {
            throw SocketException(strerror(errno));
        }
    }

    //Function to close the socket.
    void ServerSocket::close() {
        if (false == socket_->close()) {
            throw SocketException(strerror(errno));
        }
    }

} // namespace ftp_utilities
} // namespace mde

#ifndef MDE_SOCKETEXCEPTION_CLASS
#define MDE_SOCKETEXCEPTION_CLASS

#include <string>
#include <cerrno>

namespace mde { namespace ftp_utilities {

    class SocketException {
    private:
        std::string message;

    public:
        SocketException(std::string);
        ~SocketException();
        std::string description();
    };

} // namespace ftp utilities
} // namespace mde

#endif // MDE_SOCKETEXCEPTION_CLASS

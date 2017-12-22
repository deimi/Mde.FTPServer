#ifndef MDE_FTP_RESPONSE_H
#define MDE_FTP_RESPONSE_H

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>


namespace mde { namespace ftp_utilities {

    class FTPResponse {
    private:
        std::string _msg;
        std::string status_code;
    public:
        FTPResponse();
        FTPResponse(std::string);
        FTPResponse(std::string, std::string);
        ~FTPResponse();
        void setResponse(std::string);
        int32_t returnCode();
        std::string parseResponse();
        std::string parseResponse(int32_t&);
        std::string formResponse();
        int32_t getPort();
    };

} // namespace ftp_utilities
} // namespace mde

#endif // MDE_FTP_RESPONSE_H

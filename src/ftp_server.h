#ifndef MDE_FTP_SERVER_H
#define MDE_FTP_SERVER_H

// TODO Move includes to cpp files
// TODO Cleanup all headers
// TODO Sort all headers
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <fcntl.h>

#include "utilities/server_socket.h"
#include "utilities/socket_exception.h"
#include "utilities/utility.h"
#include "utilities/ftp_request.h"
#include "utilities/ftp_response.h"

namespace mde {

    class FTPServer {
    public:
        // TODO Replace LoginInfo with Container class and provide it at Constructor
        typedef std::map<std::string, pair<std::string, std::string> > LoginInfo;
        FTPServer(int32_t);
        ~FTPServer();
        void start();

    private:
        int32_t port;

        FTPServer();
        int32_t ls(std::string, std::string&, bool print = false);
        std::string syst(bool print = false);
        std::string pwd(bool print = false);
        int32_t cd(std::string, bool print = false);
        int32_t mkd(std::string, std::string&, bool print = false);
        int32_t pasv();
        bool quit();
        int32_t setRootDir(std::string, bool print = false);
        LoginInfo formLoginInfoList();
        void clientHandler(ftp_utilities::ServerSocket*);
        void communicate(ftp_utilities::ServerSocket*);
    };

} // namespace mde

#endif // MDE_FTP_SERVER_H 

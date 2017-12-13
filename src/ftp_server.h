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
// TODO Seperate Windows/Linux includes


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
        //TODO Use std types (int32_t,...)
        FTPServer(int);
        ~FTPServer();
        void start();

    private:
        int port;

        FTPServer();
        int ls(std::string, std::string&, bool print = false);
        std::string syst(bool print = false);
        std::string pwd(bool print = false);
        int cd(std::string, bool print = false);
        int mkd(std::string, std::string&, bool print = false);
        int pasv();
        bool quit();
        int setRootDir(std::string, bool print = false);
        LoginInfo formLoginInfoList();
        void clientHandler(ftp_utilities::ServerSocket*);
        void communicate(ftp_utilities::ServerSocket*);
    };

} // namespace mde

#endif // MDE_FTP_SERVER_H 

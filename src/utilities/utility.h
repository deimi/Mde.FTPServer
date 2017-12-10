#ifndef MDE_UTILITY_H
#define MDE_UTILITY_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "operating_system.h"

#include "socket_exception.h"

namespace mde { namespace ftp_utilities {

    static int RVAL = 0;

    int hostlookup(std::string);
    bool is_number(std::string);

    std::string getFileName(std::string);
    std::string getFilePath(std::string);
    std::string exec_cmd(std::string, std::string, int& code = RVAL);
    std::vector<std::string> tokenize(std::string, std::string);
    bool parseCommand(std::string, std::string&, std::string&);
    bool parseCommand(std::string, std::string&, std::vector<std::string>&, std::vector<std::string>&);

} // namespace ftp_utilities
} // namespace mde

#endif // MDE_UTILITY_H

#ifndef MDE_BASIC_LOGIN_INFO_H
#define MDE_BASIC_LOGIN_INFO_H

// The BasicLoginInfo class provides basic functionality for login information of the ftp server.
// There are no features regarding secure storing of the access credentials and the home folder of the user.
// All data is stored as plained text string.


#include "i_login_info.h"

namespace mde { namespace ftp_utilities {
    
    class BasicLoginInfo : public ILoginInfo {
        
    };

} // namespace ftp_utilities
} // namespace mde

#endif // MDE_BASIC_LOGIN_INFO_H
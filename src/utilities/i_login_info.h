#ifndef MDE_I_LOGIN_INFO_H
#define MDE_I_LOGIN_INFO_H

#include <string>

namespace mde { namespace ftp_utilities {
    
    class ILoginInfo {
    public:
        enum LoginInfoReturn {
            loginInfoAccessGranted,
            loginInfoAccessDenied
        };
        LoginInfoReturn checkAccess(const std::string& aUser, const std::string& aPass);
        LoginInfoReturn getHomeFolder(const std::string& aUser, const std::string& aPass, std::string& aHomeFolder);
    };

} // namespace ftp_utilities
} // namespace mde


#endif // MDE_I_LOGIN_INFO_H
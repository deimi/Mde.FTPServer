#ifndef MDE_LOGGING_H
#define MDE_LOGGING_H

#include <cstdint>

#include <iostream>
#include <string>

// TODO Replace logging enabling with better solution (meta programming)
#define MDE_LOGGING_ON

namespace mde {
    
    class Log {
    public:
       
        template<class T>
        Log& operator<< (T aParam) {
#ifdef MDE_LOGGING_ON
            std::cout << aParam;
#endif
            return *this;
        }

        template<>
        Log& operator<<<Log&(*)(Log&)> (Log&(*aParam) (Log&)) {
            return (*aParam)(*this);
        }

        Log& endl();

    };

    extern Log log;
    Log& endl(Log&);

} // namespace mde

#endif // MDE_LOGGING_H
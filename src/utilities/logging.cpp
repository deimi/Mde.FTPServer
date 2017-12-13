
#include "logging.h"


namespace mde {
    
    Log log;

    Log& endl(Log&) {
        return log.endl();
    }

    Log& Log::endl() {
        return operator<<("\n");
    }

} // namespace mde
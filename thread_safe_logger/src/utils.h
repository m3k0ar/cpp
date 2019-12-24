#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <cstdlib>

namespace logging {
    enum class log_level : uint8_t
    {
        TRACE = 0,
        DEBUG = 1,
        INFO = 2,
        WARNING = 3,
        ERROR = 4
    };
}

#endif // UTILS_H

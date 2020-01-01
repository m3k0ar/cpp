#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <string>
#include <unordered_map>
#include <chrono>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <fstream>
#include <mutex>
#include <memory>

// logging_config_t = std::unordered_map<std::string, std::string>

namespace logging {

    enum class log_level : uint8_t
    {
        TRACE       = 0,
        DEBUG       = 1,
        INFO        = 2,
        WARN        = 3,
        ERROR       = 4
    };

    struct enum_hasher
    {
        template <typename T>
        std::size_t operator()(T t) const
        {
            return static_cast<std::size_t>(t);
        }
    };

    const std::unordered_map<log_level, std::string, enum_hasher> uncolored
    {
        {log_level::ERROR, " [ERROR] "},
        {log_level::WARN, " [WARN] "},
        {log_level::INFO, " [INFO] "},
        {log_level::DEBUG, " [DEBUG] "},
        {log_level::TRACE, " [TRACE] "}
    };

    const std::unordered_map<log_level, std::string, enum_hasher> colored
    {
        {log_level::ERROR, " \x1b[31;1m[ERROR]\x1b[0m "},
        {log_level::WARN, " \x1b[33;1m[WARN]\x1b[0m "},
        {log_level::INFO, " \x1b[32;1m[INFO]\x1b[0m "},
        {log_level::DEBUG, " \x1b[34;1m[DEBUG]\x1b[0m "},
        {log_level::TRACE, " \x1b[37;1m[TRACE]\x1b[0m "}
    };

    //all, something in between, none or default to info
    #if defined(LOGGING_LEVEL_ALL) || defined(LOGGING_LEVEL_TRACE)
        constexpr log_level LOG_LEVEL_CUTOFF = log_level::TRACE;
    #elif defined(LOGGING_LEVEL_DEBUG)
        constexpr log_level LOG_LEVEL_CUTOFF = log_level::DEBUG;
    #elif defined(LOGGING_LEVEL_WARN)
        constexpr log_level LOG_LEVEL_CUTOFF = log_level::WARN;
    #elif defined(LOGGING_LEVEL_ERROR)
        constexpr log_level LOG_LEVEL_CUTOFF = log_level::ERROR;
    #elif defined(LOGGING_LEVEL_NONE)
        constexpr log_level LOG_LEVEL_CUTOFF = log_level::ERROR + 1;
    #else
        constexpr log_level LOG_LEVEL_CUTOFF = log_level::INFO;
    #endif

    //returns formatted to: 'year/mo/dy hr:mn:sc.xxxxxx'
    inline std::string timestamp()
    {
        // get time
        std::chrono::system_clock::time_point now =
                std::chrono::system_clock::now();

        time_t tt = std::chrono::system_clock::to_time_t(now);

        std::tm gmt{}; gmtime_r(&tt, &gmt);

        std::chrono::duration<double> fractional_seconds =
                (now - std::chrono::system_clock::from_time_t(tt)) +
                std::chrono::seconds(gmt.tm_sec);

        //format the string
        std::string buffer("year/mo/dy hr:mn:sc.xxxxxx");
        sprintf(&buffer.front(), "%04d/%02d/%02d %02d:%02d:%09.6f",
                gmt.tm_year, gmt.tm_mon, gmt.tm_mday,
                gmt.tm_hour, gmt.tm_min, fractional_seconds.count());

        return buffer;
    }

}

#endif // UTILS_H

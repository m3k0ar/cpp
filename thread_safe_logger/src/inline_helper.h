#ifndef INLINE_HELPER_H
#define INLINE_HELPER_H

#include "logger.h"
#include "file_logger.h"
#include "std_out_logger.h"
#include "logger_factory.h"

namespace logging {

// statically get a factory
inline logger_factory& get_factory()
{
    static logger_factory factory_singleton{};
    return factory_singleton;
}

// get at the singleton
inline logger& get_logger(const std::unordered_map<std::string, std::string>& config = { {"type", "std_out"}, {"color", ""} })
{
    static std::unique_ptr<logger> singleton(get_factory().produce(config));
    return *singleton;
}

// configure the singleton (once only)
inline void configure(const std::unordered_map<std::string, std::string>& config)
{
    get_logger(config);
}

// statically log manually without the macros below
inline void log(const std::string& message, const log_level level) {
    get_logger().log(message, level);
}

// statically log manually without a level or maybe with a custom one
inline void log(const std::string& message) {
    get_logger().log(message);
}

// these standout when reading code
inline void TRACE(const std::string& message)
{
    get_logger().log(message, log_level::TRACE);
}
inline void DEBUG(const std::string& message)
{
    get_logger().log(message, log_level::DEBUG);
}
inline void INFO(const std::string& message)
{
    get_logger().log(message, log_level::INFO);
}
inline void WARN(const std::string& message)
{
    get_logger().log(message, log_level::WARN);
}
inline void ERROR(const std::string& message)
{
    get_logger().log(message, log_level::ERROR);
}

}

#endif // INLINE_HELPER_H

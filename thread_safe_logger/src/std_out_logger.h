#ifndef STD_OUT_LOGGER_H
#define STD_OUT_LOGGER_H

#include "utils.h"
#include "logger.h"

namespace logging {

class std_out_logger : public logger
{
public:
    std_out_logger() = delete;
    std_out_logger(const std::unordered_map<std::string, std::string>& config);
    virtual void log(const std::string& message, const log_level level) override;
    virtual void log(const std::string& message) override;

protected:
    const std::unordered_map<log_level, std::string, enum_hasher> levels;
};

}


#endif // STD_OUT_LOGGER_H

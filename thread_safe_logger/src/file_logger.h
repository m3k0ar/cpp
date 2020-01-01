#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include "logger.h"
#include "utils.h"

namespace logging {

/*
* logger that writes to file
*/
class file_logger : public logger
{
public:
    file_logger() = delete;
    file_logger(const std::unordered_map<std::string, std::string>& config);
    virtual void log(const std::string& message, const log_level level) override;
    virtual void log(const std::string& message) override;

protected:
    void reopen();
    std::string file_name;
    std::ofstream file;
    std::chrono::seconds reopen_interval;
    std::chrono::system_clock::time_point last_reopen;
};

}
#endif // FILE_LOGGER_H

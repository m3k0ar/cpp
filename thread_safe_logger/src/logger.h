#ifndef LOGGER_H
#define LOGGER_H

#include "utils.h"
// logger base class, not pure virtual
// so you can use as a null logger if you want

namespace logging {

class logger
{
public:
    logger() = delete;
    logger(const std::unordered_map<std::string, std::string>&) : lock{}
    {}
    virtual ~logger(){}
    virtual void log(const std::string&, const log_level){}
    virtual void log(const std::string&){}

protected:
    std::mutex lock;
};

} // logging


#endif // LOGGER_H

#ifndef LOGGER_FACTORY_H
#define LOGGER_FACTORY_H

#include "logger.h"
#include "utils.h"
#include "file_logger.h"
#include "std_out_logger.h"

namespace logging {

/*
* a factory that can create loggers (that derive from 'logger')
* via function pointers
* this way you could make your own logger that sends log messages
* to who knows where
*/

using logger_creator =
    logger *(*)(const std::unordered_map<std::string, std::string>&);

class logger_factory
{
public:
    logger_factory();
    logger* produce(const std::unordered_map<std::string, std::string>& config) const;

protected:
    std::unordered_map<std::string, logger_creator> creators;
};

}


#endif // LOGGER_FACTORY_H

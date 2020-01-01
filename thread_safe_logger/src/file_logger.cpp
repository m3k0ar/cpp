#include "file_logger.h"


namespace logging {

file_logger::file_logger(const std::unordered_map<std::string, std::string> &config) :
    logger(config)
{
    //grab the file name
    auto name = config.find("file_name");
    if(name == config.end())
    {
        throw std::runtime_error("No output file provided to file logger");
    }
    file_name = name->second;

    //if we specify an interval

}

}


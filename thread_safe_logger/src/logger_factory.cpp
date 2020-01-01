#include "logger_factory.h"

namespace logging {

logger_factory::logger_factory() : creators{}
{
    creators.emplace("", [](const std::unordered_map<std::string, std::string>& config)->logger*{return new logger(config);});
    creators.emplace("std_out", [](const std::unordered_map<std::string, std::string>& config)->logger*{return new std_out_logger(config);});
    creators.emplace("file", [](const std::unordered_map<std::string, std::string>& config)->logger*{return new file_logger(config);});
}

logger *logger_factory::produce(const std::unordered_map<std::string, std::string> &config) const
{
    // grab the type
    auto type = config.find("type");
    if(type == config.end())
    {
        throw std::runtime_error("Logging factory configuration requires a type of logger");
    }

    //grab the logger
    auto found = creators.find(type->second);
    if(found != creators.end())
    {
        return found->second(config);
    }

    //couldn't get a logger
    throw std::runtime_error("Couldn't produce logger for type: " + type->second);
}

}



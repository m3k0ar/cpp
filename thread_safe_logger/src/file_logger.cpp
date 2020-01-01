#include "file_logger.h"


namespace logging {

file_logger::file_logger(const std::unordered_map<std::string, std::string> &config) :
    logger(config),
    file_name{},
    file{},
    reopen_interval{},
    last_reopen{}
{
    // grab the file name
    auto name = config.find("file_name");
    if(name == config.end())
    {
        throw std::runtime_error("No output file provided to file logger");
    }
    file_name = name->second;

    // if we specify an interval
    reopen_interval = std::chrono::seconds(300);
    auto interval = config.find("reopen_interval");

    if(interval != config.end())
    {
        try
        {
          reopen_interval = std::chrono::seconds(std::stoul(interval->second));
        }
        catch(...)
        {
          throw std::runtime_error(interval->second +
                                   " is not a valid reopen interval");
        }
    }

    // crack the file open
    reopen();
}

void file_logger::log(const std::string &message, const log_level level)
{
    if(level < LOG_LEVEL_CUTOFF)
    {
        return;
    }
    std::string output;
    output.reserve(message.length() + 64);
    output.append(timestamp());
    output.append(uncolored.find(level)->second);
    output.append(message);
    output.push_back('\n');
    log(output);
}

void file_logger::log(const std::string &message)
{
    lock.lock();
    file << message;
    file.flush();
    lock.unlock();
    reopen();
}

void file_logger::reopen()
{
   // check if it should be closed and reopened
    auto now = std::chrono::system_clock::now();
    lock.lock();

    if(now - last_reopen > reopen_interval)
    {
        last_reopen = now;
        try
        {
            file.close();
        }
        catch(...)
        {}

        try
        {
          file.open(file_name, std::ofstream::out | std::ofstream::app);
          last_reopen = std::chrono::system_clock::now();
        }
        catch(std::exception& e)
        {
          try
            {
                file.close();
            }
            catch(...)
            {}
          throw e;
        }
    }

    lock.unlock();
}

}


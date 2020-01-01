#include "std_out_logger.h"

namespace logging {

std_out_logger::std_out_logger(const std::unordered_map<std::string, std::string>& config) :
    logger(config), levels(config.find("color") != config.end() ? colored : uncolored)
{}

void std_out_logger::log(const std::string &message, const log_level level)
{
    if(level < LOG_LEVEL_CUTOFF)
    {
        return;
    }

    std::string output;
    output.reserve(message.length() + 64);
    output.append(timestamp());
    output.append(levels.find(level)->second);
    output.append(message);
    output.push_back('\n');
    log(output);
}

/*
 *cout is thread safe, to avoid multiple threads interleaving on one line
 * though, we make sure to only call the << operator once on std::cout
 * otherwise the << operators from different threads could interleave
 * obviously we dont care if flushes interleave
*/
void std_out_logger::log(const std::string &message)
{
    std::cout << message;
    std::cout.flush();
}



} // logging


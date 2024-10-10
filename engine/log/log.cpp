

#include <vector>
#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

std::shared_ptr<spdlog::logger> Log::m_Logger;
std::shared_ptr<spdlog::logger> Log::m_AppLogger;

bool Log::Init()
{
    bool ok = false;
    std::vector<spdlog::sink_ptr> logSink;
    logSink.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

    spdlog::set_pattern("%^[%T] %n: %v%$");
    m_Logger = std::make_shared<spdlog::logger>("Engine", begin(logSink), end(logSink));
    if (m_Logger)
    {
        ok = true;
        spdlog::register_logger(m_Logger);
        m_Logger->set_level(spdlog::level::trace);
        m_Logger->flush_on(spdlog::level::trace);
    }

    m_AppLogger = std::make_shared<spdlog::logger>("Application", begin(logSink), end(logSink));
    if (m_AppLogger)
    {
        ok = true;
        spdlog::register_logger(m_AppLogger);
        m_Logger->set_level(spdlog::level::trace);
        m_Logger->flush_on(spdlog::level::trace);
    }

    return ok;
}


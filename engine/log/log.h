

#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

class Log
{
public:
    static bool Init();
    
    inline static std::shared_ptr<spdlog::logger>& GetLogger() 
    {
        return m_Logger;
    }
    
    inline static std::shared_ptr<spdlog::logger>& GetAppLogger() 
    {
        return m_AppLogger;
    }

private: 

    static std::shared_ptr<spdlog::logger> m_Logger;
    static std::shared_ptr<spdlog::logger> m_AppLogger;

};

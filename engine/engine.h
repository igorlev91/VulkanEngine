

#pragma once

#include <iostream>
#include <chrono>

#include "log.h"

#undef far
#undef near
#undef CopyFile
#undef CreateDirectory

#define ASSERT(x) if (!(x)) std::cout << " (ASSERT on line number " << __LINE__ << " in file " << __FILE__ << ")" << std::endl;
#define member_size(type, member) sizeof(((type *)0)->member)
#define BIT(x) (1 << (x))
#define CastToFloat(x) (((float*)(&x))[0])

#define LOG_CORE_TRACE(...)    Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...)     Log::GetLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)     Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)    Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CORE_CRITICAL(...) Log::GetLogger()->critical(__VA_ARGS__)

#define LOG_APP_TRACE(...)    Log::GetAppLogger()->trace(__VA_ARGS__)
#define LOG_APP_INFO(...)     Log::GetAppLogger()->info(__VA_ARGS__)
#define LOG_APP_WARN(...)     Log::GetAppLogger()->warn(__VA_ARGS__)
#define LOG_APP_ERROR(...)    Log::GetAppLogger()->error(__VA_ARGS__)
#define LOG_APP_CRITICAL(...) Log::GetAppLogger()->critical(__VA_ARGS__)

typedef uint8_t  uchar;
typedef uint32_t uint;
typedef int64_t  int64;
typedef uint64_t uint64;

using namespace std::chrono_literals;

#define ENUM_CLASS_BITOPS(T) \
    static inline T operator |(const T &lhs, const T &rhs) { \
        return T((int)lhs | (int)rhs); \
    } \
    static inline T &operator |= (T &lhs, const T &rhs) { \
        lhs = lhs | rhs; \
        return lhs; \
    } \
    static inline bool operator &(const T &lhs, const T &rhs) { \
        return ((int)lhs & (int)rhs) != 0; \
    }

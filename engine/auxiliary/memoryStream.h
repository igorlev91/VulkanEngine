

#pragma once

#include <iostream>
#include <streambuf>

#include "resources.h"

class memoryBuffer : public std::basic_streambuf<char>
{
    
public:

    memoryBuffer(const uint8_t *dataPointer, size_t length)
    {
        setg((char*)dataPointer, (char*)dataPointer, (char*)dataPointer + length);
    }
    
    memoryBuffer(const char* path /* GNU */, int resourceID /* MSVC */, const std::string& resourceClass /* MSVC */)
    {
        size_t length;
        char* dataPointer = (char*) ResourceSystem::GetDataPointer(length, path, resourceID, resourceClass);
        setg((char*)dataPointer, (char*)dataPointer, (char*)dataPointer + length);
    }
    
};


class memoryStream : public std::istream 
{

public:

    memoryStream(const uint8_t *dataPointer, size_t length) 
        : std::istream(&m_Buffer), m_Buffer(dataPointer, length)
    {
        rdbuf(&m_Buffer);
    }
    
    memoryStream(const char* path /* GNU */, int resourceID /* MSVC */, const std::string& resourceClass /* MSVC */) 
        : std::istream(&m_Buffer), m_Buffer(path, resourceID, resourceClass)
    {
        rdbuf(&m_Buffer);
    }

private:
  memoryBuffer m_Buffer;
};

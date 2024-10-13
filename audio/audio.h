

#pragma once

#include <memory>
#include <iostream>

#include "engine.h"

class Audio
{

public:

    enum class AudioBackend
    {
        SDL,
        OPEN_AL,
        FFMPEG
    };

public:

    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void PlaySound(const std::string& filename) = 0;
    virtual void PlaySound(const char* path, int resourceID, const std::string& resourceClass) = 0;

    static std::shared_ptr<Audio> Create();
    static AudioBackend GetBackend() { return AudioBackend::SDL; }

};

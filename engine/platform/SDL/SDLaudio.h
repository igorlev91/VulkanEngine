

#pragma once

#include <iostream>

#include "engine.h"
#include "audio.h"
#include "SDL_mixer.h"

class SDLAudio: public Audio
{

public:

    virtual void Start() override;
    virtual void Stop() override;
    virtual void PlaySound(const std::string& filename) override;
    virtual void PlaySound(const char* path, int resourceID, const std::string& resourceClass) override;

private:

    static constexpr uint SOUND_CHANNELS = 2;
    Mix_Chunk* m_DataBuffer[SOUND_CHANNELS];

};



#include "audio.h"
#include "sound.h"
#include "SDLaudio.h"

std::shared_ptr<Audio> Audio::Create()
{
    std::shared_ptr<Audio> audio;

    switch(GetBackend())
    {
        case AudioBackend::SDL:
            audio = std::make_shared<SDLAudio>();
            break;
        default:
            audio = nullptr;
            break;
    }
    Sound::Start();
    return audio;
}

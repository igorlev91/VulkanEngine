

#include <iostream>

#include "SDLaudio.h"
#include "SDL.h"
#include "resources.h"

void SDLAudio::Start()
{
    SDL_InitSubSystem(SDL_INIT_AUDIO);

    // Set up the audio stream
    int result = Mix_OpenAudio(44100, AUDIO_S16SYS, SOUND_CHANNELS, 512);
    if( result < 0 )
    {
        std::string errorMessage = SDL_GetError();
        LOG_CORE_WARN("Unable to open audio: {0}", errorMessage);
        return;
    }

    result = Mix_AllocateChannels(4);
    if( result < 0 )
    {
        std::string errorMessage = SDL_GetError();
        LOG_CORE_WARN("Unable to allocate mixing channels: {0}", errorMessage);
        return;
    }
}

void SDLAudio::Stop()
{
    for( int i = 0; i < SOUND_CHANNELS; i++ )
    {
        Mix_FreeChunk(m_DataBuffer[i]);
    }

    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}

void SDLAudio::PlaySound(const std::string& filename)
{
    memset(m_DataBuffer, 0, sizeof(Mix_Chunk*) * SOUND_CHANNELS);

    // load sound file from disk
    for (int i = 0; i < SOUND_CHANNELS; i++)
    {
        m_DataBuffer[i] = Mix_LoadWAV(filename.c_str());
        if (m_DataBuffer[i] == nullptr)
        {
            LOG_CORE_WARN("SDLAudio::PlaySound: Unable to load sound file: {0}, Mix_GetError(): {1}", filename, Mix_GetError());
            return;
        }
    }
    Mix_PlayChannel(-1, m_DataBuffer[0], 0);
}

void SDLAudio::PlaySound(const char* path, int resourceID, const std::string& resourceClass)
{
    memset(m_DataBuffer, 0, sizeof(Mix_Chunk*) * SOUND_CHANNELS);

    // load file from memory
    size_t fileSize;
    void* data = (void*)ResourceSystem::GetDataPointer(fileSize, path, resourceID, resourceClass);

    for (int i = 0; i < SOUND_CHANNELS; i++)
    {
        SDL_RWops* sdlRWOps = SDL_RWFromMem(data, fileSize);
        if (!sdlRWOps)
        {
            LOG_CORE_WARN("SDLAudio::PlaySound: Resource '{0}' not found", path);
            return; 
        }

        m_DataBuffer[i] = Mix_LoadWAV_RW(sdlRWOps, 0);
        if (m_DataBuffer[i] == nullptr)
        {
            LOG_CORE_WARN("SDLAudio::PlaySound: Unable to load sound file: {0}, Mix_GetError(): {1}", path, Mix_GetError());
            return;
        }
    }
    Mix_PlayChannel(-1, m_DataBuffer[0], 0);
}

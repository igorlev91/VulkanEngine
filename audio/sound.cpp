

#include <iostream>
#include <stdio.h>

#include "sound.h"

#ifdef LINUX

    using namespace LibPAmanager;

    SoundDeviceManager* Sound::m_SoundDeviceManager;

    void Sound::Start()
    {
        m_SoundDeviceManager = SoundDeviceManager::GetInstance();
        m_SoundDeviceManager->Start();
    }

    uint Sound::GetDesktopVolume()
    {
        uint desktopVolume = 0;
        desktopVolume = m_SoundDeviceManager->GetVolume();
        return desktopVolume;
    }

    void Sound::SetDesktopVolume(uint desktopVolume)
    {
        m_SoundDeviceManager->SetVolume(desktopVolume);
    }

    std::vector<std::string>& Sound::GetOutputDeviceList()
    {
        return m_SoundDeviceManager->GetOutputDeviceList();
    }

    void Sound::SetOutputDevice(const std::string& outputDevice)
    {
        m_SoundDeviceManager->SetOutputDevice(outputDevice);
    }

    void Sound::SetCallback(std::function<void(const LibPAmanager::Event&)> callback)
    {
        m_SoundDeviceManager->SetCallback(callback);
    }
    
    std::string& Sound::GetDefaultOutputDevice()
    {
        return m_SoundDeviceManager->GetDefaultOutputDevice();
    }

#else

    void Sound::Start()
    {
    }

    uint Sound::GetDesktopVolume()
    {
        uint desktopVolume = 0;
        return desktopVolume;
    }

    void Sound::SetDesktopVolume(uint desktopVolume)
    {
    }

    std::vector<std::string>& Sound::GetOutputDeviceList()
    {
        static std::vector<std::string> dummy;
        return dummy;
    }

    void Sound::SetOutputDevice(const std::string& outputDevice)
    {
    }

    std::string& Sound::GetDefaultOutputDevice()
    {
        static std::string dummy;
        return dummy;
    }

#endif

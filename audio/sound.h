

#pragma once

#include <functional>

#ifdef LINUX

    #include "engine.h"
    #include "SoundDeviceManager.h"

    class Sound
    {

    public:
        static void Start();
        static uint GetDesktopVolume();
        static std::string& GetDefaultOutputDevice();
        static void SetDesktopVolume(uint desktopVolume);
        static std::vector<std::string>& GetOutputDeviceList();
        static void SetOutputDevice(const std::string& outputDevice);
        static void SetCallback(std::function<void(const LibPAmanager::Event&)> callback);

    private:

        static LibPAmanager::SoundDeviceManager* m_SoundDeviceManager;

    };

#else

    #include "engine.h"

    class Sound
    {

    public:
        static void Start();
        static uint GetDesktopVolume();
        static std::string& GetDefaultOutputDevice();
        static void SetDesktopVolume(uint desktopVolume);
        static std::vector<std::string>& GetOutputDeviceList();
        static void SetOutputDevice(const std::string& outputDevice);

    private:

    };

#endif

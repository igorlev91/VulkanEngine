

#pragma once

// enable PROFILING in premake5.lua
#if defined(PROFILING)

    #include <chrono>
    #include <fstream>
    #include <iostream>
    #include <thread>
    #include <mutex>

	#if (defined(__FUNCSIG__) || defined(_MSC_VER))
		#define FUNC_SIGNATURE __FUNCSIG__
    #elif defined(__GNUC__)
        #define FUNC_SIGNATURE __PRETTY_FUNCTION__
	#endif

	#define PROFILE_BEGIN_SESSION(name, filepath) ::Instrumentation::SessionManager::Get().Begin(name, filepath)
	#define PROFILE_END_SESSION() ::Instrumentation::SessionManager::Get().End()

    #define PROFILE_SCOPE_LINE2(name, line) ::Instrumentation::Timer timer##line(name)
	#define PROFILE_SCOPE_LINE(name, line) PROFILE_SCOPE_LINE2(name, line)
	#define PROFILE_SCOPE(name) PROFILE_SCOPE_LINE(name, __LINE__)
    #define PROFILE_FUNCTION() PROFILE_SCOPE(FUNC_SIGNATURE)

    namespace Instrumentation
    {

        struct Result
        {
            std::string m_Name;
            std::chrono::duration<double, std::micro> m_Start;
            std::chrono::microseconds m_ElapsedTime;
            std::thread::id m_ThreadID;
        };

        struct Session
        {
            std::string m_Name;
        };

        class SessionManager
        {
        public:
            SessionManager(const SessionManager&) = delete;
            SessionManager(SessionManager&&) = delete;

            void Begin(const std::string& name, const std::string& filename = "results.json");
            void End();

            void CreateEntry(const Result& result);

            static SessionManager& Get()
            {
                static SessionManager instance;
                return instance;
            }
        private:
            SessionManager();
            ~SessionManager();

            void StartJsonFile();
            void EndJsonFile();
            void EndInternal();

        private:

            std::mutex m_Mutex;
            Session* m_CurrentSession;
            std::ofstream m_OutputStream;
            std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
        };

        class Timer
        {

        public:

            Timer(const char* name);
            ~Timer();

        private:

            const char* m_Name;
            std::chrono::time_point<std::chrono::high_resolution_clock> m_Start, m_End;

        };
    }

#else
	#define PROFILE_BEGIN_SESSION(name, filepath)
	#define PROFILE_END_SESSION()
	#define PROFILE_SCOPE(name)
	#define PROFILE_FUNCTION()
#endif


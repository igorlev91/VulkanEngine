

#include "file.h"

namespace EngineCore
{

    bool FileExists(const char* filename)
    {
        std::ifstream infile(filename);
        return infile.good();
    }

    bool FileExists(const std::string& filename)
    {
        std::ifstream infile(filename.c_str());
        return infile.good();
    }

    bool FileExists(const std::filesystem::directory_entry& filename)
    {
        return filename.exists();
    }

    bool IsDirectory(const char *filename)
    {
        std::filesystem::path path(filename);
        return is_directory(path);
    }

    bool IsDirectory(const std::string& filename)
    {
        bool isDirectory = false;
        std::filesystem::path path(filename);

        try
        {
            isDirectory = is_directory(path);
        }
        catch (...)
        {
            isDirectory = false;
        }
        return isDirectory;
    }

    std::string GetFilenameWithoutPath(const std::filesystem::path& path)
    {
        #ifndef _WIN32
            std::string filenameWithoutPath = path.filename();
        #else
            std::filesystem::path withoutPath{std::filesystem::path(path.filename())};
            std::string filenameWithoutPath = withoutPath.string();
        #endif
        return filenameWithoutPath;
    }

    std::string GetFileExtension(const std::filesystem::path& path)
    {
        #ifndef _WIN32
            std::string ext = path.extension();
        #else
            std::filesystem::path extension{std::filesystem::path(path.extension())}; 
            std::string ext = extension.string();
        #endif
        return ext;
    }

    bool CreateDirectory(const std::string& filename)
    {
        #ifdef _MSC_VER
        std::filesystem::create_directories(filename);
        return IsDirectory(filename);
        #else
        return std::filesystem::create_directories(filename);
        #endif
    }

    bool CopyFile(const std::string& src, const std::string& dest)
    {
        std::ifstream source(src.c_str(), std::ios::binary);
        std::ofstream destination(dest.c_str(), std::ios::binary);
        destination << source.rdbuf();
        return source && destination;
    }

    std::ifstream::pos_type FileSize(const std::string& filename)
    {
        std::ifstream in(filename.c_str(), std::ifstream::ate | std::ifstream::binary);
        return in.tellg(); 
    }
    
    std::string& AddSlash(std::string& filename)
    {
        #ifdef _MSC_VER
        const char* slash = "\\";
        #else
        const char* slash = "/";
        #endif

        if (filename.substr(filename.size() - 1) != slash)
        {
            filename += slash;
        }

        return filename;
    }
}



#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

namespace EngineCore
{
    bool FileExists(const char* filename);
    bool FileExists(const std::string& filename);
    bool FileExists(const std::filesystem::directory_entry& filename);

    bool IsDirectory(const char *filename);
    bool IsDirectory(const std::string& filename);

    std::string GetFilenameWithoutPath(const std::filesystem::path& path);
    std::string GetFileExtension(const std::filesystem::path& path);

    bool CreateDirectory(const std::string& filename);
    bool CopyFile(const std::string& src, const std::string& dest);
    std::ifstream::pos_type FileSize(const std::string& filename);
    std::string& AddSlash(std::string& filename);
}



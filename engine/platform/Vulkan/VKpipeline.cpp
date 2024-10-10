

#include <fstream>

#include "VKpipeline.h"

VK_Pipeline::VK_Pipeline(const std::string& filePathVertexShader_SPV, const std::string& filePathFragmentShader_SPV)
{
    CreateGraphicsPipeline(filePathVertexShader_SPV, filePathFragmentShader_SPV);
}

VK_Pipeline::~VK_Pipeline()
{
}

std::vector<char> VK_Pipeline::readFile(const std::string& filepath)
{
    std::ifstream file(filepath, std::ios::ate | std::ios::binary);

    if (!file.is_open())
    {
        LOG_CORE_CRITICAL("failed to open file: {0}", filepath);
    }

    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    // populate the buffer
    file.read(buffer.data(), fileSize);

    file.close();
    return buffer;

}

void VK_Pipeline::CreateGraphicsPipeline(const std::string& filePathVertexShader_SPV, const std::string& filePathFragmentShader_SPV)
{
    auto vertCode = readFile(filePathVertexShader_SPV);
    auto fragCode = readFile(filePathFragmentShader_SPV);
    
    LOG_APP_INFO("Vertex Shader Code Size: {0}", vertCode.size());
    LOG_APP_INFO("Fragment Shader Code Size: {0}", fragCode.size());
}

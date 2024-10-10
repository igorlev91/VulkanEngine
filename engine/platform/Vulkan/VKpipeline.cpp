

#include <fstream>

#include "VKpipeline.h"

VK_Pipeline::VK_Pipeline(std::shared_ptr<VK_Device> device,
                         const std::string& filePathVertexShader_SPV,
                         const std::string& filePathFragmentShader_SPV,
                         const PipelineConfigInfo& spec)
    : m_Device(device)
{
    CreateGraphicsPipeline(filePathVertexShader_SPV, filePathFragmentShader_SPV, spec);
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

void VK_Pipeline::CreateGraphicsPipeline(const std::string& filePathVertexShader_SPV, 
                                         const std::string& filePathFragmentShader_SPV,
                                         const PipelineConfigInfo& spec)
{
    auto vertCode = readFile(filePathVertexShader_SPV);
    auto fragCode = readFile(filePathFragmentShader_SPV);
    
    LOG_APP_INFO("Vertex Shader Code Size: {0}", vertCode.size());
    LOG_APP_INFO("Fragment Shader Code Size: {0}", fragCode.size());
}
void VK_Pipeline::CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
{

    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint*>(code.data());

    if (vkCreateShaderModule(m_Device->device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
    {
        LOG_CORE_CRITICAL("failed to create shader module");
    }

}

PipelineConfigInfo VK_Pipeline::DefaultPipelineConfigInfo(uint width, uint height)
{
    PipelineConfigInfo pipelineConfigInfo{};
    return pipelineConfigInfo;
}

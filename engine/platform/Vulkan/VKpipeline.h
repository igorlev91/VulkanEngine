

#pragma once

#include <string>
#include <memory>

#include "engine.h"
#include "VKdevice.h"

struct PipelineConfigInfo
{
    
};

class VK_Pipeline
{

public:

    VK_Pipeline(std::shared_ptr<VK_Device> device,
                const std::string& filePathVertexShader_SPV, 
                const std::string& filePathFragmentShader_SPV,
                const PipelineConfigInfo& spec);
    ~VK_Pipeline();

    VK_Pipeline(const VK_Pipeline&) = delete;
    void operator=(const VK_Pipeline&) = delete;

    static PipelineConfigInfo DefaultPipelineConfigInfo(uint width, uint height);

private:

    static std::vector<char> readFile(const std::string& filepath);
    void CreateGraphicsPipeline(const std::string& filePathVertexShader_SPV,
                                const std::string& filePathFragmentShader_SPV,
                                const PipelineConfigInfo& spec);
    void CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
private:

    std::shared_ptr<VK_Device> m_Device;
    VkPipeline m_GraphicsPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;

};

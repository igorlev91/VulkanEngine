

#pragma once

#include <string>
#include <memory>

#include "engine.h"
#include "VKdevice.h"

struct PipelineConfigInfo
{
    PipelineConfigInfo(const PipelineConfigInfo&) = delete;
    PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

    // input assembly stage
    VkPipelineViewportStateCreateInfo viewportInfo;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;

    std::vector<VkDynamicState> dynamicStateEnables;
    VkPipelineDynamicStateCreateInfo dynamicStateInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint subpass = 0;
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
    VK_Pipeline& operator=(const VK_Pipeline&) = delete;

    void Bind(VkCommandBuffer commandBuffer);

    static void DefaultPipelineConfigInfo(PipelineConfigInfo& configInfo);

private:

    static std::vector<char> readFile(const std::string& filepath);
    void CreateGraphicsPipeline(const std::string& filePathVertexShader_SPV,
                                const std::string& filePathFragmentShader_SPV,
                                const PipelineConfigInfo& configInfo);
    void CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
private:

    std::shared_ptr<VK_Device> m_Device;
    VkPipeline m_GraphicsPipeline;
    VkShaderModule m_VertShaderModule;
    VkShaderModule m_FragShaderModule;

};

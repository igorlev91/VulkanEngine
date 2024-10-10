

#pragma once

#include <string>
#include <memory>

#include "engine.h"

class VK_Pipeline
{

public:

    VK_Pipeline(const std::string& filePathVertexShader_SPV, const std::string& filePathFragmentShader_SPV);
    ~VK_Pipeline();

    VK_Pipeline(const VK_Pipeline&) = delete;
    VK_Pipeline& operator=(const VK_Pipeline&) = delete;

private:
    static std::vector<char> readFile(const std::string& filepath);
    void CreateGraphicsPipeline(const std::string& filePathVertexShader_SPV, const std::string& filePathFragmentShader_SPV);

};

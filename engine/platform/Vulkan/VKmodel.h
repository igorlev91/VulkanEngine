

#pragma once

#include <memory>
#include <vector>

#include "engine.h"
#include "VKdevice.h"

class VK_Model
{
    
public:

    struct Vertex
    {
        glm::vec2 position;

        static std::vector<VkVertexInputBindingDescription> GetBindingDescriptions();
        static std::vector<VkVertexInputAttributeDescription> GetAttributeDescriptions();
    };

public:

    VK_Model(std::shared_ptr<VK_Device> device, const std::vector<Vertex>& verticies);
    ~VK_Model();

    VK_Model(const VK_Model&) = delete;
    void operator=(const VK_Model&) = delete;

    void CreateVertexBuffers(const std::vector<Vertex>& verticies);

    void Bind(VkCommandBuffer commandBuffer);
    void Draw(VkCommandBuffer commandBuffer);

private:
    std::shared_ptr<VK_Device> m_Device;
    VkBuffer m_VertexBuffer;
    VkDeviceMemory m_VertexBufferMemory;
    uint m_VertexCount;
};

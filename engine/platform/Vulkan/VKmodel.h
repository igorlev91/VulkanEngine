

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
        glm::vec3 color;

        static std::vector<VkVertexInputBindingDescription> GetBindingDescriptions();
        static std::vector<VkVertexInputAttributeDescription> GetAttributeDescriptions();
    };

public:

    VK_Model(std::shared_ptr<VK_Device> device, const std::vector<Vertex>& vertices);
    ~VK_Model();

    VK_Model(const VK_Model&) = delete;
    VK_Model& operator=(const VK_Model&) = delete;

    void CreateVertexBuffers(const std::vector<Vertex>& vertices);

    void Bind(VkCommandBuffer commandBuffer);
    void Draw(VkCommandBuffer commandBuffer);

private:
    std::shared_ptr<VK_Device> m_Device;
    VkBuffer m_VertexBuffer;
    VkDeviceMemory m_VertexBufferMemory;
    uint m_VertexCount;
};

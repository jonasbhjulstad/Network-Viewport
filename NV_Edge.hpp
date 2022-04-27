#ifndef NV_EDGE_HPP
#define NV_EDGE_HPP
#include "Vulkan/NV_VulkanInitializers.hpp"
#include <glm/glm.hpp>
#include <vector>
struct EdgeInstanceData
{
    glm::vec3 startNode;
    glm::vec3 endNode;
    glm::vec3 scale;

    // Per-Instance attributes
    static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions(uint32_t bind_ID, uint32_t layoutOffset)
    {
        return {
            initializers::vertexInputAttributeDescription(bind_ID, layoutOffset, VK_FORMAT_R32G32B32_SFLOAT, 0),                     // StartPos
            initializers::vertexInputAttributeDescription(bind_ID, layoutOffset + 1, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float)*3),                     // EndPos
            initializers::vertexInputAttributeDescription(bind_ID, layoutOffset + 2, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float)*6),                     // Scale
        };
    }
};

#endif
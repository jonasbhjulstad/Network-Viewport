#ifndef GLTF_BASIC_INSTANCE_PIPELINE_HPP
#define GLTF_BASIC_INSTANCE_PIPELINE_HPP
#include <vector>
#include "vulkanexamplebase.h"
#include "VulkanglTFModel.h"
#include "NV_Assets.hpp"

enum glTFBasicInstanceBindIDs
{
    GLTF_BIP_INSTANCE_BIND_ID,
    GLTF_BIP_VERTEX_BIND_ID
};

struct BasicInstancePipelineData
{
    vkglTF::Model model;
    vks::Texture2D texture;
    vks::Buffer instanceBuffer;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkDescriptorSet descriptorSet;
    VkPipeline pipeline;
    VkDeviceSize offset;
    uint32_t N_instances;
};

struct BasicInstancedRenderingParams
{
    std::string &vertexShaderPath;
    std::string &fragmentShaderPath;
    std::string &modelPath;
    std::string &texturePath;
    vks::VulkanDevice *vulkanDevice;
    vks::Buffer *uniformProjectionBuffer;
    VkQueue queue;
    VkDescriptorPool descriptorPool;
    VkPipelineCache pipelineCache = nullptr;
};

template <typename InstanceData>
vks::Buffer prepareInstanceBuffer(std::vector<InstanceData> &instanceData)
{
    vks::Buffer instanceBuffer;
    uint32_t N_instances = static_cast<uint32_t>(instanceData.size());
    instanceBuffer.size = N_instances * sizeof(InstanceData);

    struct
    {
        VkDeviceMemory memory;
        VkBuffer buffer;
    } stagingBuffer;

    VK_CHECK_RESULT(vulkanDevice->createBuffer(
        VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
        instanceBuffer.size,
        &stagingBuffer.buffer,
        &stagingBuffer.memory,
        instanceData.data()));

    VK_CHECK_RESULT(vulkanDevice->createBuffer(
        VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
        instanceBuffer.size,
        &instanceBuffer.buffer,
        &instanceBuffer.memory));

    VkCommandBuffer copyCmd = vulkanDevice->createCommandBuffer(VK_COMMAND_BUFFER_LEVEL_PRIMARY, true);

    VkBufferCopy copyRegion = {};
    copyRegion.size = instanceBuffer.size;
    vkCmdCopyBuffer(
        copyCmd,
        stagingBuffer.buffer,
        instanceBuffer.buffer,
        1,
        &copyRegion);

    vulkanDevice->flushCommandBuffer(copyCmd, queue, true);

    instanceBuffer.descriptor.range = instanceBuffer.size;
    instanceBuffer.descriptor.buffer = instanceBuffer.buffer;
    instanceBuffer.descriptor.offset = 0;

    // Destroy staging resources
    vkDestroyBuffer(device, stagingBuffer.buffer, nullptr);
    vkFreeMemory(device, stagingBuffer.memory, nullptr);

    return instanceBuffer;
}

std::vector<VkDescriptorPoolSize> getPoolSizes()
{
    return {vks::initializers::descriptorPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1),
            vks::initializers::descriptorPoolSize(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1)};
}

VkDescriptorSetLayout uniformDescriptorSetLayout(VkDevice device)
{

    std::vector<VkDescriptorSetLayoutBinding> setLayoutBindings = {
        // Binding 0 : Vertex shader uniform buffer
        vks::initializers::descriptorSetLayoutBinding(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_VERTEX_BIT, 0),
    };

    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorSetLayoutCreateInfo descriptorLayout = vks::initializers::descriptorSetLayoutCreateInfo(setLayoutBindings);
    VK_CHECK_RESULT(vkCreateDescriptorSetLayout(device, &descriptorLayout, nullptr, &descriptorSetLayout));

    return descriptorSetLayout;
}

VkDescriptorSetLayout textureDescriptorSetLayout(VkDevice device)
{

    std::vector<VkDescriptorSetLayoutBinding> setLayoutBindings = {
        // Binding 0 : Vertex shader uniform buffer
        vks::initializers::descriptorSetLayoutBinding(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_VERTEX_BIT, 0),
        vks::initializers::descriptorSetLayoutBinding(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, VK_SHADER_STAGE_FRAGMENT_BIT, 1)};

    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorSetLayoutCreateInfo descriptorLayout = vks::initializers::descriptorSetLayoutCreateInfo(setLayoutBindings);
    VK_CHECK_RESULT(vkCreateDescriptorSetLayout(device, &descriptorLayout, nullptr, &descriptorSetLayout));

    return descriptorSetLayout;
}

VkPipelineLayout setupPipelineLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout)
{
    VkPipelineLayout pipelineLayout;
    // Pipeline layout
    VkPipelineLayoutCreateInfo pPipelineLayoutCreateInfo = vks::initializers::pipelineLayoutCreateInfo(&descriptorSetLayout, 1);
    VK_CHECK_RESULT(vkCreatePipelineLayout(device, &pPipelineLayoutCreateInfo, nullptr, &pipelineLayout));
    return pipelineLayout;
}

VkDescriptorSet setupDescriptorSets(VkDevice device,
                                    VkDescriptorSetLayout descriptorSetLayout,
                                    VkDescriptorPool descriptorPool,
                                    vks::Buffer *uniformProjectionBuffer,
                                    vks::Texture *texture = nullptr)
{
    VkDescriptorSet descriptorSet;
    VkDescriptorSetAllocateInfo allocInfo = vks::initializers::descriptorSetAllocateInfo(descriptorPool, &descriptorSetLayout, 1);

    VK_CHECK_RESULT(vkAllocateDescriptorSets(device, &allocInfo, &descriptorSet));

    std::vector<VkWriteDescriptorSet> writeDescriptorSets = {
        vks::initializers::writeDescriptorSet(descriptorSet, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 0, &uniformProjectionBuffer->descriptor)};
    if (texture)
    {
        writeDescriptorSets.push_back(vks::initializers::writeDescriptorSet(descriptorSet, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1, &texture->descriptor));
    }
    vkUpdateDescriptorSets(device, static_cast<uint32_t>(writeDescriptorSets.size()), writeDescriptorSets.data(), 0, nullptr);

    return descriptorSet;
}

template <typename InstanceData>
VkPipeline setupPipeline(const std::string &vertexShaderPath,
                         const std::string &fragmentShaderPath,
                         VkPipelineLayout pipelineLayout,
                         VkPipelineCache pipelineCache = VK_NULL_HANDLE)
{
    std::vector<VkPipelineShaderStageCreateInfo> shaderStages(2);
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyState = vks::initializers::pipelineInputAssemblyStateCreateInfo(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, 0, VK_FALSE);
    VkPipelineRasterizationStateCreateInfo rasterizationState = vks::initializers::pipelineRasterizationStateCreateInfo(VK_POLYGON_MODE_FILL, VK_CULL_MODE_BACK_BIT, VK_FRONT_FACE_COUNTER_CLOCKWISE);
    VkPipelineColorBlendAttachmentState blendAttachmentState = vks::initializers::pipelineColorBlendAttachmentState(0xf, VK_FALSE);
    VkPipelineColorBlendStateCreateInfo colorBlendState = vks::initializers::pipelineColorBlendStateCreateInfo(1, &blendAttachmentState);
    VkPipelineDepthStencilStateCreateInfo depthStencilState = vks::initializers::pipelineDepthStencilStateCreateInfo(VK_TRUE, VK_TRUE, VK_COMPARE_OP_LESS_OR_EQUAL);
    VkPipelineViewportStateCreateInfo viewportState = vks::initializers::pipelineViewportStateCreateInfo(1, 1, 0);
    VkPipelineMultisampleStateCreateInfo multisampleState = vks::initializers::pipelineMultisampleStateCreateInfo(VK_SAMPLE_COUNT_1_BIT);
    std::vector<VkDynamicState> dynamicStateEnables = {VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR};
    VkPipelineDynamicStateCreateInfo dynamicState = vks::initializers::pipelineDynamicStateCreateInfo(dynamicStateEnables);

    VkGraphicsPipelineCreateInfo pipelineCI = vks::initializers::pipelineCreateInfo(pipelineLayout, renderPass);
    pipelineCI.pInputAssemblyState = &inputAssemblyState;
    pipelineCI.pRasterizationState = &rasterizationState;
    pipelineCI.pColorBlendState = &colorBlendState;
    pipelineCI.pMultisampleState = &multisampleState;
    pipelineCI.pViewportState = &viewportState;
    pipelineCI.pDepthStencilState = &depthStencilState;
    pipelineCI.pDynamicState = &dynamicState;
    pipelineCI.stageCount = static_cast<uint32_t>(2);
    pipelineCI.pStages = shaderStages.data();

    pipelineCI.layout = pipelineLayout;

    // Vertex input bindings
    // The instancing pipeline uses a vertex input state with two bindings
    std::vector<VkVertexInputBindingDescription> bindingDescriptions = {
        // Binding point 0: Mesh vertex layout description at per-vertex rate
        vks::initializers::vertexInputBindingDescription(GLTF_BIP_INSTANCE_BIND_ID, sizeof(vkglTF::Vertex), VK_VERTEX_INPUT_RATE_VERTEX),
        // Binding point 1: Instanced data at per-instance rate
        vks::initializers::vertexInputBindingDescription(GLTF_BIP_INSTANCE_BIND_ID, sizeof(InstanceData), VK_VERTEX_INPUT_RATE_INSTANCE)};

    std::vector<VkVertexInputAttributeDescription> attributeDescriptions = {
        vks::initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 0, VK_FORMAT_R32G32B32_SFLOAT, 0),                 // Location 0: Position
        vks::initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 1, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 3), // Location 1: Normal
        vks::initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 2, VK_FORMAT_R32G32_SFLOAT, sizeof(float) * 6),    // Location 2: Texture coordinates
        vks::initializers::vertexInputAttributeDescription(GLTF_BIP_VERTEX_BIND_ID, 3, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 8), // Location 3: Color
    };

    std::vector<VkVertexInputAttributeDescription> instanceDataDescriptions = InstanceData::getAttributeDescriptions(GLTF_BIP_INSTANCE_BIND_ID, 4);

    attributeDescriptions.insert(attributeDescriptions.end(), instanceDataDescriptions.begin(), instanceDataDescriptions.end());
    VkPipelineVertexInputStateCreateInfo inputState = vks::initializers::pipelineVertexInputStateCreateInfo();
    inputState.pVertexBindingDescriptions = bindingDescriptions.data();
    inputState.pVertexAttributeDescriptions = attributeDescriptions.data();

    inputState.vertexBindingDescriptionCount = static_cast<uint32_t>(bindingDescriptions.size());
    inputState.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
    pipelineCI.pVertexInputState = &inputState;
    pipelineCI.layout = pipelineLayout;

    shaderStages[0] = loadShader(vertexShaderPath, VK_SHADER_STAGE_VERTEX_BIT);
    shaderStages[1] = loadShader(fragmentShaderPath, VK_SHADER_STAGE_FRAGMENT_BIT);

    VkPipeline pipeline;
    VK_CHECK_RESULT(vkCreateGraphicsPipelines(device, pipelineCache, 1, &pipelineCI, nullptr, &pipeline));
    return pipeline;
}

void buildCommandBuffer(
    VkPipelineLayout pipelineLayout,
    VkPipeline pipeline,
    VkDescriptorSet descriptorSet,
    vkglTF::Model *model,
    VkBuffer instanceBuffer,
    VkCommandBuffer drawCmdBuffer,
    VkDeviceSize offsets,
    uint32_t N_instances)
{
    vkCmdBindDescriptorSets(drawCmdBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout, 0, 1, &descriptorSet, 0, nullptr);
    vkCmdBindPipeline(drawCmdBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline);

    vkCmdBindVertexBuffers(drawCmdBuffer, GLTF_BIP_VERTEX_BIND_ID, 1, &model->vertices.buffer, &offsets);
    vkCmdBindVertexBuffers(drawCmdBuffer, GLTF_BIP_INSTANCE_BIND_ID, 1, &instanceBuffer, &offsets);

    vkCmdBindIndexBuffer(drawCmdBuffer, model->indices.buffer, 0, VK_INDEX_TYPE_UINT32);

    vkCmdDrawIndexed(drawCmdBuffer, model->indices.count, N_instances, 0, 0, 0);
}

void buildCommandBuffer(BasicInstancePipelineData& BI_data, VkCommandBuffer commandBuffer)
{
    buildCommandBuffer(BI_data.pipelineLayout,
    BI_data.pipeline, 
    BI_data.descriptorSet, 
    BI_data.model,
    BI_data.instanceBuffer,
    commandBuffer,
    BI_data.offset,
    BI_data.N_instances);
}

template <typename InstanceData>
BasicInstancePipelineData prepareBasicInstancedRendering(std::vector<InstanceData> &instanceData,
                                                         BasicInstancedRenderingParams &p)
{

    VkDevice device = p.vulkanDevice->logicalDevice;

    BasicInstancePipelineData BI_data;

    BI_data.model = loadModel(p.modelPath, p.vulkanDevice, p.queue);
    BI_data.instanceBuffer = prepareInstanceBuffer(instanceData);
    if (!p.texture.empty())
    {
        BI_data.texture = loadTexture(p.texturePath, p.vulkanDevice, p.queue);
        BI_data.descriptorSetLayout = textureDescriptorSetLayout(device);
    }
    else
    {
        BI_data.descriptorSetLayout = uniformDescriptorSetLayout(device);
    }
    BI_data.pipelineLayout = setupPipelineLayout(device, p.descriptorSetLayout);
    BI_data.descriptorSet = setupDescriptorSets(device, p.descriptorSetLayout, p.descriptorPool, p.uniformProjectionBuffer);
    BI_data.pipeline = setupPipeline(p.vertexShaderPath, p.fragmentShaderPath, p.pipelineLayout, p.pipelineCache);
    BI_data.descriptorSet = setupDescriptorSets(p.descriptorPool);

    return BI_data;
}

#endif
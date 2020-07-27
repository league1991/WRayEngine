#pragma once

#include <vulkan/vulkan.h>
#include <vector>

class Buffer
{
public:
    enum class Type
    {
        BUFFER_VERTEX,
        BUFFER_INDEX,
    };
    Buffer() {}
    ~Buffer();

    void init(VkDevice device, Type type, const void* data, int dataSize, int dataStride, VkPhysicalDeviceMemoryProperties& memory_properties, bool useUV);
    void destroy(VkDevice device)
    {
        vkDestroyBuffer(device, buf, NULL);
        vkFreeMemory(device, mem, NULL);
    }
//private:
    VkBuffer buf;
    VkDeviceMemory mem;
    VkDescriptorBufferInfo buffer_info;
    VkVertexInputBindingDescription vi_binding;
    VkVertexInputAttributeDescription vi_attribs[2];
};


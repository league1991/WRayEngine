#include <assert.h>

#include "Application.h"
#include "Buffer.h"



void Buffer::init(VkDevice device, Type type, const void* data, int dataSize, int dataStride, VkPhysicalDeviceMemoryProperties& memory_properties, bool useUV)
{
    VkBufferUsageFlags usage;
    switch (type)
    {
    case Buffer::Type::BUFFER_VERTEX:
        usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
        break;
    case Buffer::Type::BUFFER_INDEX:
        usage = VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
        break;
    default:
        break;
    }

    VkResult U_ASSERT_ONLY res;
    bool U_ASSERT_ONLY pass;

    VkBufferCreateInfo buf_info = {};
    buf_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buf_info.pNext = NULL;
    buf_info.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
    buf_info.size = dataSize;
    buf_info.queueFamilyIndexCount = 0;
    buf_info.pQueueFamilyIndices = NULL;
    buf_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    buf_info.flags = 0;
    res = vkCreateBuffer(device, &buf_info, NULL, &buf);
    assert(res == VK_SUCCESS);

    VkMemoryRequirements mem_reqs;
    vkGetBufferMemoryRequirements(device, buf, &mem_reqs);

    VkMemoryAllocateInfo alloc_info = {};
    alloc_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    alloc_info.pNext = NULL;
    alloc_info.memoryTypeIndex = 0;

    alloc_info.allocationSize = mem_reqs.size;
    pass = memory_type_from_properties(memory_properties, mem_reqs.memoryTypeBits,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
        &alloc_info.memoryTypeIndex);
    assert(pass && "No mappable, coherent memory");

    res = vkAllocateMemory(device, &alloc_info, NULL, &(mem));
    assert(res == VK_SUCCESS);
    buffer_info.range = mem_reqs.size;
    buffer_info.offset = 0;

    uint8_t* pData;
    res = vkMapMemory(device, mem, 0, mem_reqs.size, 0, (void**)&pData);
    assert(res == VK_SUCCESS);

    memcpy(pData, data, dataSize);

    vkUnmapMemory(device, mem);

    res = vkBindBufferMemory(device, buf, mem, 0);
    assert(res == VK_SUCCESS);

    vi_binding.binding = 0;
    vi_binding.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
    vi_binding.stride = dataStride;

    vi_attribs[0].binding = 0;
    vi_attribs[0].location = 0;
    vi_attribs[0].format = VK_FORMAT_R32G32B32A32_SFLOAT;
    vi_attribs[0].offset = 0;

    vi_attribs[1].binding = 0;
    vi_attribs[1].location = 1;
    vi_attribs[1].format = useUV ? VK_FORMAT_R32G32_SFLOAT : VK_FORMAT_R32G32B32A32_SFLOAT;
    vi_attribs[1].offset = 16;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //VkResult res;
    //VkBufferCreateInfo buf_info = {};
    //buf_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    //buf_info.pNext = NULL;
    //buf_info.usage = usage;
    //buf_info.size = size;
    //buf_info.queueFamilyIndexCount = 0;
    //buf_info.pQueueFamilyIndices = NULL;
    //buf_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    //buf_info.flags = 0;
    //res = vkCreateBuffer(device, &buf_info, NULL, &buf);
    //assert(res == VK_SUCCESS);

    //VkMemoryRequirements mem_reqs;
    //vkGetBufferMemoryRequirements(device, buf, &mem_reqs);

    //VkMemoryAllocateInfo alloc_info = {};
    //alloc_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    //alloc_info.pNext = NULL;
    //alloc_info.memoryTypeIndex = 0;

    //alloc_info.allocationSize = mem_reqs.size;
    //bool pass = memory_type_from_properties(memory_properties, mem_reqs.memoryTypeBits,
    //    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
    //    &alloc_info.memoryTypeIndex);
    //assert(pass && "No mappable, coherent memory");

    //res = vkAllocateMemory(device, &alloc_info, NULL, &(mem));
    //assert(res == VK_SUCCESS);

    //uint8_t *pData;
    //res = vkMapMemory(device, mem, 0, mem_reqs.size, 0, (void **)&pData);
    //assert(res == VK_SUCCESS);

    //memcpy(pData, data, size);

    //vkUnmapMemory(device, mem);

    //res = vkBindBufferMemory(device, buf, mem, 0);
    //assert(res == VK_SUCCESS);
}


Buffer::~Buffer()
{
}

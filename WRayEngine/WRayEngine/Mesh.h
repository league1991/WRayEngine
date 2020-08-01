#pragma once

#include "tiny_obj_loader.h"
#include <vulkan/vulkan.h>

#include "Buffer.h"

class ObjLoader
{
public:
    enum VertexAttributeType
    {
        VERTEX_ATTRIBUTE_POSITION = 0x1,
        VERTEX_ATTRIBUTE_NORMAL   = 0x2,
        VERTEX_ATTRIBUTE_TEXCOORD = 0x4,
        VERTEX_ATTRIBUTE_COLOR    = 0x8,
    };
    void Load(const char* fileName);
    bool GetVertexBuffer(int shapeIndex, unsigned type, std::vector<float>& buffer, int& numberVertices, int& sizeOfPerVertex);

    tinyobj::attrib_t m_attrib;
    std::vector<tinyobj::shape_t> m_shapes;
    std::vector<tinyobj::material_t> m_materials;
    std::string m_warn;
    std::string m_err;
};

class Mesh
{
public:
    Mesh();
    ~Mesh();

    void load(const char* fileName, VkDevice device, VkPhysicalDeviceMemoryProperties& memory_properties);

    void draw(VkCommandBuffer cmd);

    std::vector<Buffer> m_vertexBuffers;
};


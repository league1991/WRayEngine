
#define TINYOBJLOADER_IMPLEMENTATION

#include "Mesh.h"



Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::load(const char * fileName, VkDevice device, VkPhysicalDeviceMemoryProperties & memory_properties)
{
    ObjLoader loader;
    loader.Load(fileName);

    int numBuffers = loader.m_shapes.size();
    m_vertexBuffers.resize(numBuffers);
    for (int i = 0; i < numBuffers; i++)
    {
        std::vector<float> buffer;
        int numVertices, sizeOfVertex;
        loader.GetVertexBuffer(i, ObjLoader::VERTEX_ATTRIBUTE_POSITION | ObjLoader::VERTEX_ATTRIBUTE_TEXCOORD, buffer, numVertices, sizeOfVertex);
        m_vertexBuffers[i].init(device, Buffer::Type::BUFFER_VERTEX, &buffer[0], numVertices, sizeOfVertex, memory_properties, true);
    }
}

void Mesh::draw(VkCommandBuffer cmd)
{
    const VkDeviceSize offsets[1] = { 0 };
    for (int i = 0; i < m_vertexBuffers.size(); i++)
    {
        vkCmdBindVertexBuffers(cmd, 0, 1, &m_vertexBuffers[i].buf, offsets);
        vkCmdDraw(cmd, m_vertexBuffers[i].m_numVertex, 1, 0, 0);
    }
}

void ObjLoader::Load(const char * fileName)
{
    tinyobj::LoadObj(&m_attrib, &m_shapes, &m_materials, &m_warn, &m_err, fileName);
}

bool ObjLoader::GetVertexBuffer(int shapeIndex, unsigned type, std::vector<float>& buffer, int & numberVertices, int & sizeOfPerVertex)
{
    if (shapeIndex >= m_shapes.size())
    {
        return false;
    }
    if (m_attrib.vertices.size() == 0)
    {
        return false;
    }
    int numberOfFloats = 0;
    if ((type & VERTEX_ATTRIBUTE_POSITION) != 0)
    {
        numberOfFloats += 3;
    }
    if ((type & VERTEX_ATTRIBUTE_NORMAL) != 0)
    {
        numberOfFloats += 3;
    }
    if ((type & VERTEX_ATTRIBUTE_TEXCOORD) != 0)
    {
        numberOfFloats += 2;
    }
    if ((type & VERTEX_ATTRIBUTE_COLOR) != 0)
    {
        numberOfFloats += 3;
    }
    sizeOfPerVertex = numberOfFloats * sizeof(float);

    auto& shape = m_shapes[shapeIndex];
    numberVertices = shape.mesh.indices.size();

    buffer.resize(numberVertices * numberOfFloats);
    for (int i = 0; i < numberVertices; i++)
    {
        auto& idx = shape.mesh.indices[i];
        float* p = &buffer[i * numberOfFloats];
        if ((type & VERTEX_ATTRIBUTE_POSITION) != 0)
        {
            if (idx.vertex_index >= 0)
            {
                p[0] = m_attrib.vertices[idx.vertex_index * 3];
                p[1] = m_attrib.vertices[idx.vertex_index * 3 + 1];
                p[2] = m_attrib.vertices[idx.vertex_index * 3 + 2];
            }
            else
            {
                p[0] = p[1] = p[2] = 0;
            }
            p += 3;
        }
        if ((type & VERTEX_ATTRIBUTE_NORMAL) != 0)
        {
            if (idx.normal_index >= 0)
            {
                p[0] = m_attrib.normals[idx.normal_index * 3];
                p[1] = m_attrib.normals[idx.normal_index * 3 + 1];
                p[2] = m_attrib.normals[idx.normal_index * 3 + 2];
            }
            else
            {
                p[0] = p[1] = p[2] = 0;
            }
            p += 3;
        }
        if ((type & VERTEX_ATTRIBUTE_TEXCOORD) != 0)
        {
            if (idx.texcoord_index >= 0)
            {
                p[0] = m_attrib.texcoords[idx.texcoord_index * 2];
                p[1] = m_attrib.texcoords[idx.texcoord_index * 2 + 1];
            }
            else
            {
                p[0] = p[1] = 0;
            }
            p += 2;
        }
        if ((type & VERTEX_ATTRIBUTE_COLOR) != 0)
        {
            if (idx.vertex_index >= 0)
            {
                p[0] = m_attrib.colors[idx.vertex_index * 3];
                p[1] = m_attrib.colors[idx.vertex_index * 3 + 1];
                p[2] = m_attrib.colors[idx.vertex_index * 3 + 2];
            }
            else
            {
                p[0] = p[1] = p[2] = 0;
            }
        }
    }
    return true;
}

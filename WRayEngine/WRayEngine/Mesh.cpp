
#define TINYOBJLOADER_IMPLEMENTATION

#include "Mesh.h"



Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void ObjLoader::Load(const char * fileName)
{
    tinyobj::LoadObj(&m_attrib, &m_shapes, &m_materials, &m_warn, &m_err, fileName);
}

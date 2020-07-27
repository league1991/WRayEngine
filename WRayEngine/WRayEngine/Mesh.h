#pragma once

#include "tiny_obj_loader.h"


class ObjLoader
{
public:
    void Load(const char* fileName);

private:
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

    static Mesh* createFromObjMesh()
    {

    }
};


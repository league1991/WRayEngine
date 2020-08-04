#include "Application.h"
#include "Mesh.h"
//#include <util_init.hpp>


int main(int argc, char* argv[]) {

    //const char *filename = "E:\\Code\\WRayEngine\\WRayEngine\\WRayEngine\\cornell_box.obj";
    //ObjLoader loader;
    //loader.Load(filename);

    //std::vector<float> buffer;
    //int numVertex, sizeOfPerVertex;
    //loader.GetVertexBuffer(0,ObjLoader::VERTEX_ATTRIBUTE_POSITION | ObjLoader::VERTEX_ATTRIBUTE_COLOR,
    //    buffer, numVertex, sizeOfPerVertex);

    Application* app = Application::instance();

    app->initialize();

    while (!app->shouldExit())
    {
        app->update();
    }

    app->destroy();
    return 0;
}

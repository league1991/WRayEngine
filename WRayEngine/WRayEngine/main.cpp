#include "Application.h"
#include "Mesh.h"
//#include <util_init.hpp>


int main(int argc, char* argv[]) {

    const char *filename = "E:\\Code\\WRayEngine\\WRayEngine\\WRayEngine\\cornell_box.obj";
    ObjLoader loader;
    loader.Load(filename);

    Application app;

    app.initialize();

    while (!app.shouldExit())
    {
        app.update();
    }

    app.destroy();
    return 0;
}

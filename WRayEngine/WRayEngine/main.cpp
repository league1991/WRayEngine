#include "Application.h"
//#include <util_init.hpp>


int main(int argc, char* argv[]) {
    Application app;

    app.initialize();

    while (!app.shouldExit())
    {
        app.update();
    }

    app.destroy();
    return 0;
}

#include <iostream>

#include "App.h"

int main(int argc, char **argv) {
    App app;
    if(app.init()) {
        app.loop();
        app.cleanUp();
    }
    return 0;
}


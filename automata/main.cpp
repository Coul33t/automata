#include <iostream>
#include "include/engine.hpp"

int main() {
    std::cout << "Hello World!" << std::endl;

    Engine engine;
    if(engine.init(1280, 640)) {
        engine.run();
    }

    return 0;
}
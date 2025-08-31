#include <memory>

#include "scene.h"

int main() {
    const auto scene = std::make_unique<Scene>();
    scene->draw();
    return 0;
}

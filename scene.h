//
// Created by David Richter on 8/31/25.
//

#pragma once

#include <raylib.h>
#include <rlgl.h>


class Scene {
public:
    Scene();

    ~Scene();

    void update();

    void draw();

private:
    Camera m_camera { 0 };
    static constexpr int m_width { 1280 };
    static constexpr int m_height { 720 };
};

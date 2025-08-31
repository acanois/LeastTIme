//
// Created by David Richter on 8/31/25.
//

#include "scene.h"

#include <iostream>
#include <__ostream/basic_ostream.h>

Scene::Scene()
    : m_camera(
        Vector3 { 0.f, 25.f, 0.0001f },
        Vector3 { 0.f, 0.f, 0.f },
        Vector3 { 0.f, 1.f, 0.f },
        45.f,
        CAMERA_PERSPECTIVE
    ) {
    InitWindow(m_width, m_height, "Least Time");
    SetTargetFPS(60);
}

Scene::~Scene() {
    CloseWindow();
}

void Scene::update() {
}


void Scene::draw() {
    auto angle = 90.f;
    while (WindowShouldClose() == false) {
        ClearBackground(Color { 24, 29, 39, 255 });
        auto rotation = angle * static_cast<float>(M_PI) / 180.f;
        update();

        BeginDrawing();
        BeginMode3D(m_camera);

        rlPushMatrix();
        DrawPlane(
            Vector3 { 0.f, 0.f, 0.f },
            Vector2 { 10.f, 10.f },
            Color { 125, 130, 184, 255 }
        );
        rlPopMatrix();

        EndMode3D();
        EndDrawing();
    }
}

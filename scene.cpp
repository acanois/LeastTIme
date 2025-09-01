//
// Created by David Richter on 8/31/25.
//

#include "scene.h"

#include <iostream>
#include <__ostream/basic_ostream.h>

Scene::Scene()
    : m_camera(
        Vector3 { 24.f, 6.f, 0.f },
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

float Scene::angleToRads(const float angle) {
    return angle * static_cast<float>(M_PI) / 180.f;
}

void Scene::setPositionToOverhead() {
    m_camera.position = Vector3 { 0.f, 36.f, 0.0001f };
}

void Scene::updateOrbitalCamera(const float angle, const float radius) {
    m_camera.position = Vector3 {
        cos(angleToRads(angle)) * radius,
        10.f,
        sin(angleToRads(angle)) * radius,
    };
}


void Scene::draw() {
    float angle = 0.f;
    float radius = 24.f;

    while (WindowShouldClose() == false) {
        constexpr float planeScale = 24.f;

        ClearBackground(Color { 24, 24, 24, 255 });

        if (IsKeyPressed(KEY_TWO)) setPositionToOverhead();

        update();
        // updateOrbitalCamera(angle, radius);

        BeginDrawing();
        BeginMode3D(m_camera);

        rlPushMatrix();
        DrawPlane(
            Vector3 { 0.f, 0.f, 0.f },
            Vector2 { planeScale, planeScale },
            Color { 168, 168, 168, 255 }
        );
        rlPopMatrix();

        constexpr auto num_pillars = 12;
        constexpr auto angleIncrement = 360.f / static_cast<float>(num_pillars);

        for (auto i = 0; i < num_pillars; ++i) {
            const auto theta = angleToRads(angle);
            rlPushMatrix();
            rlTranslatef(sin(theta) * 9.f, 0.f, cos(theta) * 9.f);
            DrawCylinder(
                Vector3 { 0.f, 0.f, 0.f },
                0.5f,
                0.5f,
                planeScale / 6.f,
                planeScale / 2.f,
                Color { 24, 24, 24, 255 }
            );
            rlPopMatrix();
            angle += angleIncrement;
        }

        EndMode3D();
        EndDrawing();
    }
}

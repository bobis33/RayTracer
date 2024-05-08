/*
** EPITECH PROJECT, 2024
** Raytracer | core
** File description:
** core.cpp
*/

#include <algorithm>

#include "RayTracer/Core.hpp"

void RayTracer::Core::runRayTracer(Scene &scene)
{
    ARenderer& renderer = *scene.getRenderer();
    double aspectRatio = (static_cast<double>(renderer.getResolution().getWidth()) / static_cast<double>(renderer.getResolution().getHeight()));
    scene.getCamera().setCameraScreen({{-aspectRatio, -1, 0}, {2 * aspectRatio, 0, 0}, {0, 2, 0}});

    std::vector<AShape*> sortedShapes;
    for(const auto &shape : scene.getShapes()) {
        sortedShapes.push_back(shape.get());
    }
    std::sort(sortedShapes.begin(), sortedShapes.end(), [&scene](AShape* a, AShape* b) {
        return a->getDistance(scene.getCamera().getOrigin()).length() < b->getDistance(scene.getCamera().getOrigin()).length();
    });

    renderer.render(sortedShapes, scene.getCamera());
}

/*
** EPITECH PROJECT, 2024
** Raytracer | core
** File description:
** core.cpp
*/

#include <algorithm>

#include "RayTracer/Core.hpp"

void rtr::Core::runRayTracer(Scene &scene)
{
    ARenderer& renderer = *scene.getRenderer();
    double aspectRatio = (static_cast<double>(renderer.getResolution().getWidth()) / static_cast<double>(renderer.getResolution().getHeight()));
    scene.getCamera().setCameraScreen({{-aspectRatio, -1, 0}, {2 * aspectRatio, 0, 0}, {0, 2, 0}});

    std::vector<AShape*> sortedShapes;
    for(const auto &shape : scene.getShapes()) {
        sortedShapes.push_back(shape.get());
    }
    renderer.render(sortedShapes, scene.getLights(), scene.getCamera());
}

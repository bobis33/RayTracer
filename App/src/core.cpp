/*
** EPITECH PROJECT, 2024
** Raytracer | core
** File description:
** core.cpp
*/

#include "RayTracer/Core.hpp"

void RayTracer::Core::runRayTracer(Scene &scene)
{
    ARenderer& renderer = *scene.getRenderer();
    double aspectRatio = (static_cast<double>(renderer.getResolution().getWidth()) / static_cast<double>(renderer.getResolution().getHeight()));
    scene.getCamera().setCameraScreen({{-aspectRatio, -1, 0}, {2 * aspectRatio, 0, 0}, {0, 2, 0}});
    renderer.render(scene.getShapes(), scene.getCamera());
}

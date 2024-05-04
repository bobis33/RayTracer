/*
** EPITECH PROJECT, 2024
** Raytracer | core
** File description:
** core.cpp
*/

#include "RayTracer/Core.hpp"

void RayTracer::Core::runRayTracer(const Scene &scene)
{
    scene.getRenderer()->render();
}

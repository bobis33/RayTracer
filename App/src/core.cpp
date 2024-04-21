/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Core.cpp
*/

#include "RayTracer/Core.hpp"

void RayTracer::Core::runRayTracer(const Scene &scene)
{
    scene.getRenderer()->render();
}

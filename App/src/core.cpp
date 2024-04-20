/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Core.cpp
*/

#include "RayTracer/Core.hpp"

#include "RayTracer/Factory/RendererFactory.hpp"

void RayTracer::Core::runRayTracer(Scene &scene)
{
    scene.getRenderer()->render();
}

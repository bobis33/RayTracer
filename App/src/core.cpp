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
    scene.getRenderer()->render(scene.getShapes(), scene.getLights(), scene.getCamera());
}

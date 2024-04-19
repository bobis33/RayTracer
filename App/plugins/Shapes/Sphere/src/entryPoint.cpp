/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** SphereShape.cpp
*/

#include <memory>

#include "RayTracer/SphereShape.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AShapes> entryPoint()
    {
        return std::make_unique<RayTracer::SphereShape>();
    }
}

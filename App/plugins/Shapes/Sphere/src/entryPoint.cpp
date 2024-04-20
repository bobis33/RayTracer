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
    std::unique_ptr<RayTracer::AShape> entryPoint()
    {
        return std::make_unique<RayTracer::SphereShape>();
    }
}

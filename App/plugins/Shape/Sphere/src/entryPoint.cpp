/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/Sphere.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AShape> entryPoint()
    {
        return std::make_unique<RayTracer::Sphere>();
    }
}

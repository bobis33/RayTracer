/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** CylinderShape.cpp
*/

#include <memory>

#include "RayTracer/CylinderShape.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AShapes> entryPoint()
    {
        return std::make_unique<RayTracer::CylinderShape>();
    }
}

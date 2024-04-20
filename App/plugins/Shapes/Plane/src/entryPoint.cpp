/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** PlaneShape.cpp
*/

#include <memory>

#include "RayTracer/PlaneShape.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AShape> entryPoint()
    {
        return std::make_unique<RayTracer::PlaneShape>();
    }
}

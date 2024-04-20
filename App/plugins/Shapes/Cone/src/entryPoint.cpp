/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** ConeShape.cpp
*/

#include <memory>

#include "RayTracer/ConeShape.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AShape> entryPoint()
    {
        return std::make_unique<RayTracer::ConeShape>();
    }
}

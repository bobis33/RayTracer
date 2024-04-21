/*
** EPITECH PROJECT, 2024
** Raytracer | FlatColor
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/FlatColor.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AMaterial> entryPoint()
    {
        return std::make_unique<RayTracer::FlatColor>();
    }
}

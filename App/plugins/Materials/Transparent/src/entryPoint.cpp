/*
** EPITECH PROJECT, 2024
** Raytracer | Transparent
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/Transparent.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AMaterial> entryPoint()
    {
        return std::make_unique<RayTracer::Transparent>();
    }
}

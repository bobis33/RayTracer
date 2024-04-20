/*
** EPITECH PROJECT, 2024
** Raytracer | Color
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/Color.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::AMaterial> entryPoint()
    {
        return std::make_unique<RayTracer::Color>();
    }
}

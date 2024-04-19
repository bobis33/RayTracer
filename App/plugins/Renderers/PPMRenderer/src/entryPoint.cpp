/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/PpmRenderer.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::ARenderer> entryPoint()
    {
        return std::make_unique<RayTracer::PpmRenderer>();
    }
}

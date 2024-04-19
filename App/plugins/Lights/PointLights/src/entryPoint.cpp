/*
** EPITECH PROJECT, 2024
** RayTracer | Lights
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/PointLights.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::ALights> entryPoint()
    {
        return std::make_unique<RayTracer::PointLights>();
    }
}

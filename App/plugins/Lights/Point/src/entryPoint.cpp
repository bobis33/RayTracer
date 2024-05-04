/*
** EPITECH PROJECT, 2024
** RayTracer | Lights
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/PointLight.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::ALight> entryPoint()
    {
        return std::make_unique<RayTracer::PointLight>();
    }
}

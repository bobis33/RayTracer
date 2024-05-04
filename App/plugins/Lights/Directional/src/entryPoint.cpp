/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/DirectionalLight.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::ALight> entryPoint()
    {
        return std::make_unique<RayTracer::DirectionalLight>();
    }
}

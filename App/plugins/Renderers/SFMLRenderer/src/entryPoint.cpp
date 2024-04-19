/*
** EPITECH PROJECT, 2024
** RayTracer | renderer
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/SfmlRenderer.hpp"

extern "C"
{
    std::unique_ptr<RayTracer::ARenderer> entryPoint()
    {
        return std::make_unique<RayTracer::SfmlRenderer>();
    }
}
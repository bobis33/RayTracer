/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/Ambient.hpp"

extern "C"
{
    std::unique_ptr<rtr::ALight> entryPoint()
    {
        return std::make_unique<rtr::Ambient>();
    }
}

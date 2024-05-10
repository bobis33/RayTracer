/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/PPM.hpp"

extern "C"
{
    std::unique_ptr<rtr::ARenderer> entryPoint()
    {
        return std::make_unique<rtr::PPM>();
    }
}

/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/Plane.hpp"

extern "C"
{
    std::unique_ptr<rtr::AShape> entryPoint()
    {
        return std::make_unique<rtr::Plane>();
    }
}

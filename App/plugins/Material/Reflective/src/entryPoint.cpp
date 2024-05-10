/*
** EPITECH PROJECT, 2024
** Raytracer | Reflective
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/Reflective.hpp"

extern "C"
{
    std::unique_ptr<rtr::AMaterial> entryPoint()
    {
        return std::make_unique<rtr::Reflective>();
    }
}

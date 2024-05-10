/*
** EPITECH PROJECT, 2024
** RayTracer | Lights
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/Point.hpp"

extern "C"
{
    std::unique_ptr<rtr::ALight> entryPoint()
    {
        return std::make_unique<rtr::Point>();
    }
}

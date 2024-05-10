/*
** EPITECH PROJECT, 2024
** RayTracer | renderer
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "RayTracer/SFML.hpp"

extern "C"
{
    std::unique_ptr<rtr::ARenderer> entryPoint()
    {
        return std::make_unique<rtr::SFML>();
    }
}
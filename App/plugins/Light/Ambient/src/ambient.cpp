/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** ambient.cpp
*/

#include "RayTracer/Ambient.hpp"

rtr::Color rtr::Ambient::LightColor(const Vector &normal, const Vector &point, const Color &col, const std::vector<std::unique_ptr<AShape>> &shapes)
{
    (void)normal;
    (void)point;
    (void)shapes;

    return {0, 0, 0};
}

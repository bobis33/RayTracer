/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** ambient.cpp
*/

#include "RayTracer/Ambient.hpp"

rtr::Color rtr::Ambient::LightColor(const Vector &normal, const Color &col)
{
    (void)normal;
    (void)col;

    return (getColor() * getIntensity());
}

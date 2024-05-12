/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** directional.cpp
*/

#include "RayTracer/Directional.hpp"

rtr::Color rtr::Directional::LightColor(const Vector &normal, const Color &col)
{
    const Vector lightDirection = (getDirection() * -1).normalize();
    const double dotProduct = normal.normalize().dot(lightDirection);

    if (dotProduct <= EPSILON) {
        return {0, 0, 0};
    }

    return (col * getColor()) * getIntensity() * dotProduct;
}

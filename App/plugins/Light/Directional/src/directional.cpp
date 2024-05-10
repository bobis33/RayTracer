/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** directional.cpp
*/

#include "RayTracer/Directional.hpp"
#include "RayTracer/Utils/Color.hpp"
#include "RayTracer/Utils/Vector.hpp"

rtr::Color rtr::Directional::LightColor(const Vector &normal, const Vector &point, const Color &col, const std::vector<AShape*> &shapes)
{
    Vector lightDirection = getDirection() * -1;
    lightDirection = lightDirection.normalize();
    double dotProduct = normal.normalize().dot(lightDirection);
    if (dotProduct <= 0) {
        return {0, 0, 0};
    }

    for (const auto &shape : shapes) {
        RayHit hit;
        if (shape->hits({point, lightDirection}, hit) && hit.getRayHit().distance < 1e-6) {
            return {0, 0, 0};
        }
    }

    return (col * getColor()) * getIntensity() * dotProduct;
}


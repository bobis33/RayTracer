/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** directional.cpp
*/

#include "RayTracer/Directional.hpp"

rtr::Color rtr::Directional::LightColor(const Vector &normal, const Color &col)
{
    const double dotProduct = normal.normalize().dot((getDirection() * -1).normalize());

    if (dotProduct <= EPSILON) {
        return {0, 0, 0};
    }

    Color finalColor = col;
    if (finalColor.getR() <= 0) {
        finalColor.setR(static_cast<uint8_t>(getIntensity() * 50));
    } if (finalColor.getG() <= 0) {
        finalColor.setG(static_cast<const uint8_t>(getIntensity() * 50));
    } if (finalColor.getB() <= 0) {
        finalColor.setB(static_cast<const uint8_t>(getIntensity() * 50));
    }
    return (finalColor * getColor()) * getIntensity() * dotProduct;
}

/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** directional.cpp
*/

#include "RayTracer/Directional.hpp"
#include "RayTracer/Utils/Color.hpp"
#include "RayTracer/Utils/Vector.hpp"

RayTracer::Directional::Directional(Vector direction, float intensity)
{
    this->m_direction = direction;
    this->m_intensity = intensity;
}

RayTracer::Color RayTracer::Directional::LightColor(const Vector &point, const Vector &normal, RayTracer::Color col) const
{
    Vector vector = this->m_direction * -1;
    vector.normalize();
    float dot = vector.dot(normal);

    if (dot < 0) {
        return RayTracer::Color(0, 0, 0);
    }
    col.setColor(
        col.getRed() * dot * this->m_intensity,
        col.getGreen() * dot * this->m_intensity,
        col.getBlue() * dot * this->m_intensity
    );
    return col;
}

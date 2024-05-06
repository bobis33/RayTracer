/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** directional.cpp
*/

#include "RayTracer/Directional.hpp"
#include "RayTracer/Utils/Color.hpp"
#include "RayTracer/Utils/Vector.hpp"

RayTracer::Color RayTracer::Directional::LightColor(const Vector &normal, RayTracer::Color col)
{
    Vector vector = getDirection() * -1;
    vector.normalize();
    int dot = vector.dot(normal);

    if (dot < 0) {
        return RayTracer::Color(0, 0, 0);
    }
    col.setColor(
        static_cast<uint8_t>(static_cast<int>(col.getValue().r) * dot),
        static_cast<uint8_t>(static_cast<int>(col.getValue().g) * dot),
        static_cast<uint8_t>(static_cast<int>(col.getValue().b) * dot)
    );
    return col;
}

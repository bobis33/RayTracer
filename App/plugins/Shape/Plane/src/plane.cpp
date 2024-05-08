/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** PlaneShape.cpp
*/

#include "RayTracer/Plane.hpp"

bool RayTracer::Plane::hits(std::pair<Vector, Vector> ray)
{
    Vector position = getPosition();
    Vector normal = Vector(0, 1, 0);
    double denominator = position.dot(ray.second);
    if (denominator > 1e-6) {
        Vector p0l0 = position - ray.first;
        return p0l0.dot(normal) / denominator >= 0;
    }
    return false;
}

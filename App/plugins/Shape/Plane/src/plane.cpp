/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** PlaneShape.cpp
*/

#include "RayTracer/Plane.hpp"

bool rtr::Plane::hits(std::pair<Vector, Vector> ray, RayHit &hit)
{
    const Vector normal{getNormal()};
    const double d = normal.dot(getPosition());
    const double denominator = normal.dot(ray.second);
    if (denominator <= 0) {
        return false;
    }
    const double distance = (d - normal.dot(ray.first)) / denominator;
    if (distance < 1e-6) {
        return false;
    }
    hit.setDistance(distance);
    hit.setPoint(ray.first + ray.second * distance);
    hit.setNormal(normal);
    return true;
}

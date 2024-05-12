/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** PlaneShape.cpp
*/

#include "RayTracer/Plane.hpp"

bool rtr::Plane::hits(std::pair<Vector, Vector> ray, RayHit &hit)
{
    const double denominator = getPosition().dot(ray.second);
    const double distance = (getPosition() - ray.first).dot(getNormal().normalize()) / denominator;

    if (denominator < 1e-6 || distance <= 0 ) {
        return false;
    }
    hit.setDistance(distance);
    hit.setPoint(ray.first + ray.second * distance);
    hit.setNormal(getNormal().normalize());
    return true;
}

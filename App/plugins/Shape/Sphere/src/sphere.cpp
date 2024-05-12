/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** sphere.cpp
*/

#include "RayTracer/Sphere.hpp"

bool rtr::Sphere::hits(std::pair<Vector, Vector> ray, RayHit &hit)
{
    const Vector vector{ray.first - getPosition()};
    const double a = ray.second.dot(ray.second);
    const double b = 2.0 * vector.dot(ray.second);
    const double c = vector.dot(vector) - getRadius() * getRadius();
    const double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    const double t1 = (-b - sqrt(discriminant)) / (2 * a);
    const double t2 = (-b + sqrt(discriminant)) / (2 * a);
    const double distance = (t1 < t2) ? t1 : t2;

    if (distance < 1e-6) {
        return false;
    }
    hit.setDistance(distance);
    hit.setPoint(ray.first + ray.second * distance);
    hit.setNormal((hit.getRayHit().point - getPosition()).normalize());
    return true;
}

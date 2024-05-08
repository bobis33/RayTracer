/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** sphere.cpp
*/

#include "RayTracer/Sphere.hpp"

bool RayTracer::Sphere::hits(std::pair<Vector, Vector> ray)
{
    Vector vec = ray.first - getPosition();
    double a = ray.second.dot(ray.second);
    double b = 2 * vec.dot(ray.second);
    double c = vec.dot(vec) - getRadius() * getRadius();
    double discriminant = b * b - 4 * a * c;

    return discriminant > 0;
}

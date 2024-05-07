/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** Sphere.hpp
*/

#ifndef RAYTRACER_SPHERE_SHAPE_HPP
#define RAYTRACER_SPHERE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace RayTracer {

    class Sphere : public AShape {

        public:
            ~Sphere() override = default;

            [[nodiscard]] std::string getPluginName() const override { return SPHERE_SHAPE; };

        [[nodiscard]] Vector& getRotation() override { throw RunTimeException("Sphere shape does not have a rotation");};

        [[nodiscard]] bool hits(std::pair<Vector, Vector> ray) override {
            Vector vec = ray.first - getPosition();
            double a = ray.second.dot(ray.second);
            double b = 2 * vec.dot(ray.second);
            double c = vec.dot(vec) - static_cast<double>(getRadius()) * static_cast<double>(getRadius());
            double discriminant = b * b - 4 * a * c;

            return discriminant > 0;
        }


    }; // class SphereShape

} // namespace RayTracer

#endif // RAYTRACER_SPHERE_SHAPE_HPP

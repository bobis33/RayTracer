/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** Plane.hpp
*/

#ifndef RAYTRACER_PLANE_SHAPE_HPP
#define RAYTRACER_PLANE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace RayTracer {

    class Plane : public AShape {

        public:
            ~Plane() override = default;

            [[nodiscard]] std::string getPluginName() const override { return PLANE_SHAPE; };

            void setRadius(const double& radius) override { (void) radius; throw RunTimeException("Plane shape does not have a radius");};

            [[nodiscard]] double getRadius() const override { throw RunTimeException("Plane shape does not have a radius");};
            [[nodiscard]] Vector& getRotation() override { throw RunTimeException("Plane shape does not have a rotation");};

            [[nodiscard]] bool hits(std::pair<Vector, Vector> ray) override {
                Vector position = getPosition();
                Vector normal = Vector(0, 1, 0);
                double denom = getPosition().dot(ray.second);
                if (denom > 1e-6) {
                    Vector p0l0 = getPosition() - ray.first;
                    double t = p0l0.dot(normal) / denom;
                    return t >= 0;
                }
                return false;
            }
    }; // class Plane

} // namespace RayTracer

#endif // RAYTRACER_PLANE_SHAPE_HPP

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

            // MARCHE PAS JE CROIS
            
            Vector normal = getPosition().cross(Vector(0, 1, 0)).normalize();
            double dotProduct = normal.dot(ray.second);

            if (dotProduct == 0) {
                return false;
            }

            double distance = normal.dot(getPosition() - ray.first) / dotProduct;

            if (distance < 0) {
                return false;
            }

            return true;
        }



    }; // class Plane

} // namespace RayTracer

#endif // RAYTRACER_PLANE_SHAPE_HPP

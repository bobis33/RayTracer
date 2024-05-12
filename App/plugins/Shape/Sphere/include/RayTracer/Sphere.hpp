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

namespace rtr {

    class Sphere : public AShape {

        public:
            ~Sphere() override = default;

            [[nodiscard]] std::string getPluginName() const override { return SPHERE_SHAPE; };

            void setHeight(const double &height) override { (void) height; throw RunTimeException("Sphere doesnt have a height"); };

            [[nodiscard]] Vector& getRotation() override { throw RunTimeException("Sphere shape does not have a rotation");};
            [[nodiscard]] Vector &getNormal() override { throw RunTimeException("Sphere doesnt have a normal");};
            [[nodiscard]] const double &getHeight() const override { throw RunTimeException("Plane doesnt have a height"); };

            [[nodiscard]] bool hits(std::pair<Vector, Vector> ray, RayHit &hit) override;

    }; // class Sphere

} // namespace RayTracer

#endif // RAYTRACER_SPHERE_SHAPE_HPP

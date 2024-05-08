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

            [[nodiscard]] bool hits(std::pair<Vector, Vector> ray) override;


    }; // class SphereShape

} // namespace RayTracer

#endif // RAYTRACER_SPHERE_SHAPE_HPP

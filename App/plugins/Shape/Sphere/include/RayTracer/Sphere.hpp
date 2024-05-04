/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** Sphere.hpp
*/

#ifndef RAYTRACER_SPHERE_SHAPE_HPP
#define RAYTRACER_SPHERE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"

namespace RayTracer {

    class Sphere : public AShape {

        public:
            ~Sphere() override = default;

            [[nodiscard]] std::string getPluginName() const override { return SPHERE_SHAPE; };

    }; // class SphereShape

} // namespace RayTracer

#endif // RAYTRACER_SPHERE_SHAPE_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** SphereShape.hpp
*/

#ifndef RAYTRACER_SPHERE_SHAPE_HPP
#define RAYTRACER_SPHERE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"

namespace RayTracer {

    class SphereShape : public AShape {

        public:
            ~SphereShape() override = default;

            [[nodiscard]] std::string getPluginName() const override { return SPHERE_SHAPE; };

    }; // class SphereShape

} // namespace RayTracer

#endif // RAYTRACER_SPHERE_SHAPE_HPP

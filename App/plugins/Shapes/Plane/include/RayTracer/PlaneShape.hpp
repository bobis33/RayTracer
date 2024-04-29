/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** PlaneShape.hpp
*/

#ifndef RAYTRACER_PLANE_SHAPE_HPP
#define RAYTRACER_PLANE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Exceptions/RuntimeException.hpp"

namespace RayTracer {

    class PlaneShape : public AShape {

        public:
            ~PlaneShape() override = default;

            [[nodiscard]] std::string getPluginName() const override { return "PlaneShape"; };

            void setRadius(float radius) override { (void) radius; throw RunTimeException("Plane shape does not have a radius");};

            [[nodiscard]] float getRadius() const override { throw RunTimeException("Plane shape does not have a radius");};

    }; // class PlaneShape

} // namespace RayTracer

#endif // RAYTRACER_PLANE_SHAPE_HPP

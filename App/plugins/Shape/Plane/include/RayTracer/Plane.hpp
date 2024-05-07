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

    }; // class Plane

} // namespace RayTracer

#endif // RAYTRACER_PLANE_SHAPE_HPP

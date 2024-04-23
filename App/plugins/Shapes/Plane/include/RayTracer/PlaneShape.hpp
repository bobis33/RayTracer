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
#include "RayTracer/Utils/Vector3D.hpp"

namespace RayTracer {

    class PlaneShape : public AShape {

        public:
            ~PlaneShape() override = default;

            [[nodiscard]] std::string getPluginName() const override { return PLANE_SHAPE; };

            void setRadius(float radius) override { (void) radius; throw RunTimeException("Plane shape does not have a radius");};

            [[nodiscard]] float getRadius() const override { throw RunTimeException("Plane shape does not have a radius");};

            Vector3D position;
            Vector3D normal;
            double distance;
            std::string material;
    }; // class PlaneShape

} // namespace RayTracer

#endif // RAYTRACER_PLANE_SHAPE_HPP

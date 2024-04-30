/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** CylinderShape.hpp
*/

#ifndef RAYTRACER_CYLINDER_SHAPE_HPP
#define RAYTRACER_CYLINDER_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"

namespace RayTracer {

    class CylinderShape : public AShape {

        public:
            ~CylinderShape() override = default;

            [[nodiscard]] std::string getPluginName() const override { return CYLINDER_SHAPE; };

    }; // class CylinderShape

} // namespace RayTracer

#endif // RAYTRACER_CYLINDER_SHAPE_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** Cylinder.hpp
*/

#ifndef RAYTRACER_CYLINDER_SHAPE_HPP
#define RAYTRACER_CYLINDER_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace rtr {

    class Cylinder : public AShape {

        public:
            ~Cylinder() override = default;

            [[nodiscard]] std::string getPluginName() const override { return CYLINDER_SHAPE; };
            [[nodiscard]] Vector &getNormal() override { throw RunTimeException("Cylinder doesnt have a normal");};

            [[nodiscard]] bool hits(std::pair<Vector, Vector> ray) override { return false; };

    }; // class Cylinder

} // namespace RayTracer

#endif // RAYTRACER_CYLINDER_SHAPE_HPP

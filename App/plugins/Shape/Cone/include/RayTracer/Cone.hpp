/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** Cone.hpp
*/

#ifndef RAYTRACER_CONE_SHAPE_HPP
#define RAYTRACER_CONE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace rtr {

    class Cone : public AShape {

        public:
            ~Cone() override = default;

            [[nodiscard]] std::string getPluginName() const override { return CONE_SHAPE; };
            [[nodiscard]] Vector &getNormal() override { throw RunTimeException("Cone doesnt have a normal"); };

            [[nodiscard]] bool hits(std::pair<Vector, Vector> ray, RayHit &hit) override { return false; };

    }; // class Cone

} // namespace RayTracer

#endif // RAYTRACER_CONE_SHAPE_HPP

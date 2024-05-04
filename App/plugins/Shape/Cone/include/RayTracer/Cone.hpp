/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** Cone.hpp
*/

#ifndef RAYTRACER_CONE_SHAPE_HPP
#define RAYTRACER_CONE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"

namespace RayTracer {

    class Cone : public AShape {

        public:
            ~Cone() override = default;

            [[nodiscard]] std::string getPluginName() const override { return CONE_SHAPE; };

    }; // class Cone

} // namespace RayTracer

#endif // RAYTRACER_CONE_SHAPE_HPP

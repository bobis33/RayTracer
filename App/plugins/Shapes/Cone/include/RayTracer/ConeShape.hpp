/*
** EPITECH PROJECT, 2024
** Raytracer | Shapes
** File description:
** PpmRenderer.hpp
*/

#ifndef RAYTRACER_CONE_SHAPE_HPP
#define RAYTRACER_CONE_SHAPE_HPP

#include "RayTracer/Abstraction/AShape.hpp"

namespace RayTracer {

    class ConeShape : public AShape {

        public:
            ~ConeShape() override = default;

            [[nodiscard]] std::string getPluginName() const override { return "ConeShape"; };

    }; // class ConeShape

} // namespace RayTracer

#endif // RAYTRACER_CONE_SHAPE_HPP

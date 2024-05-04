/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** PointLight.hpp
*/

#ifndef RAYTRACER_POINT_LIGHT_HPP
#define RAYTRACER_POINT_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class PointLight : public ALight {

        public:
            ~PointLight() override = default;

            [[nodiscard]] std::string getPluginName() const override { return POINT_LIGHT; };

    }; // class PointLight

} // namespace RayTracer

#endif // RAYTRACER_POINT_LIGHT_HPP

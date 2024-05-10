/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** Directional.hpp
*/

#ifndef RAYTRACER_DIRECTIONAL_LIGHT_HPP
#define RAYTRACER_DIRECTIONAL_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace rtr {

    class Directional : public ALight {

        public:
            Directional() = default;
            ~Directional() override = default;

            Color LightColor(const Vector &normal, const Vector &point, const Color &col, const std::vector<AShape*> &shapes) override;

            [[nodiscard]] std::string getPluginName() const override { return DIRECTIONAL_LIGHT; };

    }; // class Directional

} // namespace RayTracer

#endif // RAYTRACER_DIRECTIONAL_LIGHT_HPP

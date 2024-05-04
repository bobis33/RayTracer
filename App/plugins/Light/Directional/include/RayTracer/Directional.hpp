/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** Directional.hpp
*/

#ifndef RAYTRACER_DIRECTIONAL_LIGHT_HPP
#define RAYTRACER_DIRECTIONAL_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class Directional : public ALight {

        public:
            ~Directional() override = default;

            [[nodiscard]] std::string getPluginName() const override { return DIRECTIONAL_LIGHT; };

    }; // class Directional

} // namespace RayTracer

#endif // RAYTRACER_DIRECTIONAL_LIGHT_HPP

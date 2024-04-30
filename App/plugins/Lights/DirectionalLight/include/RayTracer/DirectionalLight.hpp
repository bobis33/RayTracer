/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** DirectionalLight.hpp
*/

#ifndef RAYTRACER_DIRECTIONAL_LIGHT_HPP
#define RAYTRACER_DIRECTIONAL_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class DirectionalLight : public ALight {

        public:
            ~DirectionalLight() override = default;

            [[nodiscard]] std::string getPluginName() const override { return DIRECTIONAL_LIGHT; };

    }; // class DirectionalLight

} // namespace RayTracer

#endif // RAYTRACER_DIRECTIONAL_LIGHT_HPP

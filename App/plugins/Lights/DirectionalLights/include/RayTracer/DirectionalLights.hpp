/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** DirectionalLights.hpp
*/

#ifndef RAYTRACER_DIRECTIONAL_LIGHTS_HPP
#define RAYTRACER_DIRECTIONAL_LIGHTS_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class DirectionalLights : public ALight {

        public:
            ~DirectionalLights() override = default;

    }; // class DirectionalLights

} // namespace RayTracer

#endif // RAYTRACER_DIRECTIONAL_LIGHTS_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** FlatColor.hpp
*/

#ifndef RAYTRACER_AMBIENT_LIGHTS_HPP
#define RAYTRACER_AMBIENT_LIGHTS_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class AmbientLights : public ALight {

        public:
            ~AmbientLights() override = default;

    }; // class FlatColor

} // namespace RayTracer

#endif // RAYTRACER_AMBIENT_LIGHTS_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** AmbientLights.hpp
*/

#ifndef RAYTRACER_AMBIENT_LIGHTS_HPP
#define RAYTRACER_AMBIENT_LIGHTS_HPP

#include "RayTracer/Abstraction/ALights.hpp"

namespace RayTracer {

    class AmbientLights : public ALights {

        public:
            ~AmbientLights() override = default;

    }; // class AmbientLights

} // namespace RayTracer

#endif // RAYTRACER_AMBIENT_LIGHTS_HPP

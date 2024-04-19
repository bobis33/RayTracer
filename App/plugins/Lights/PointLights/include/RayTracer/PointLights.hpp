/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** PointLights.hpp
*/

#ifndef RAYTRACER_POINT_LIGHTS_HPP
#define RAYTRACER_POINT_LIGHTS_HPP

#include "RayTracer/Abstraction/ALights.hpp"

namespace RayTracer {

    class PointLights : public ALights {

        public:
            ~PointLights() override = default;

    }; // class PointLights

} // namespace RayTracer

#endif // RAYTRACER_POINT_LIGHTS_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** PointLights.hpp
*/

#ifndef RAYTRACER_POINT_LIGHTS_HPP
#define RAYTRACER_POINT_LIGHTS_HPP

#include "RayTracer/Abstraction/ILights.hpp"

namespace RayTracer {

    class PointLights : public ILights {

        public:
            ~PointLights() override = default;

    }; // class PointLights

} // namespace RayTracer

#endif // RAYTRACER_POINT_LIGHTS_HPP

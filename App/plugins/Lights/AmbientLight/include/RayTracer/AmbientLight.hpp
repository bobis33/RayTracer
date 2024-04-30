/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** AmbientLight.hpp
*/

#ifndef RAYTRACER_AMBIENT_LIGHT_HPP
#define RAYTRACER_AMBIENT_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class AmbientLight : public ALight {

        public:
            ~AmbientLight() override = default;

            [[nodiscard]] std::string getPluginName() const override { return AMBIENT_LIGHT; };

    }; // class AmbientLight

} // namespace RayTracer

#endif // RAYTRACER_AMBIENT_LIGHT_HPP

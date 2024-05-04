/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** Ambient.hpp
*/

#ifndef RAYTRACER_AMBIENT_LIGHT_HPP
#define RAYTRACER_AMBIENT_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class Ambient : public ALight {

        public:
            ~Ambient() override = default;

            [[nodiscard]] std::string getPluginName() const override { return AMBIENT_LIGHT; };

    }; // class Ambient

} // namespace RayTracer

#endif // RAYTRACER_AMBIENT_LIGHT_HPP

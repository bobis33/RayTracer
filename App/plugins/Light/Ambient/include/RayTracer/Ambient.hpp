/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** Ambient.hpp
*/

#ifndef RAYTRACER_AMBIENT_LIGHT_HPP
#define RAYTRACER_AMBIENT_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace RayTracer {

    class Ambient : public ALight {

        public:
            ~Ambient() override = default;

            [[nodiscard]] std::string getPluginName() const override { return AMBIENT_LIGHT; };

            [[nodiscard]] Vector& getDirection() override { throw RunTimeException("Ambient light has no direction");};

    }; // class Ambient

} // namespace RayTracer

#endif // RAYTRACER_AMBIENT_LIGHT_HPP

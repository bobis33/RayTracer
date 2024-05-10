/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** Point.hpp
*/

#ifndef RAYTRACER_POINT_LIGHT_HPP
#define RAYTRACER_POINT_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace rtr {

    class Point : public ALight {

        public:
            ~Point() override = default;

            [[nodiscard]] std::string getPluginName() const override { return POINT_LIGHT; };

            Color LightColor(const Vector &normal, Color col) override { return {0, 0, 0}; };

            [[nodiscard]] Vector& getDirection() override { throw RunTimeException("Ambient light has no direction");};

    }; // class Point

} // namespace RayTracer

#endif // RAYTRACER_POINT_LIGHT_HPP

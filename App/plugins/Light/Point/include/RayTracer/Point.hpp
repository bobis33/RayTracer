/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** Point.hpp
*/

#ifndef RAYTRACER_POINT_LIGHT_HPP
#define RAYTRACER_POINT_LIGHT_HPP

#include "RayTracer/Abstraction/ALight.hpp"

namespace RayTracer {

    class Point : public ALight {

        public:
            ~Point() override = default;

            [[nodiscard]] std::string getPluginName() const override { return POINT_LIGHT; };

    }; // class Point

} // namespace RayTracer

#endif // RAYTRACER_POINT_LIGHT_HPP

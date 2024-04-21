/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILight.cpp
*/

#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP

#include "RayTracer/Constants.hpp"
#include "RayTracer/Position.hpp"
#include "RayTracer/RGBColor.hpp"

namespace RayTracer {

    class ILight {

        public:
            virtual ~ILight() = default;

            virtual void setType(const LightType &type) = 0;

            [[nodiscard]] virtual LightType getType() const = 0;
            [[nodiscard]] virtual Position getPosition() const = 0;
            [[nodiscard]] virtual RGBColor getColor() const = 0;

    }; // class ILight

} // namespace RayTracer

#endif //RAYTRACER_ILIGHT_HPP

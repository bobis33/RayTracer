/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILight.cpp
*/

#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP

#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class ILight {

        public:
            virtual ~ILight() = default;

            virtual void setType(const LightType &type) = 0;
            virtual void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t> &position) = 0;

            [[nodiscard]] virtual LightType getType() const = 0;
            [[nodiscard]] virtual std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const = 0;

    }; // ILight

} // namespace RayTracer

#endif //RAYTRACER_ILIGHT_HPP

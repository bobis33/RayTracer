/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILights.cpp
*/

#ifndef RAYTRACER_ILIGHTS_HPP
#define RAYTRACER_ILIGHTS_HPP

#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class ILights {

        public:
            virtual ~ILights() = default;

            virtual void setType(const LightType &type) = 0;
            virtual void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t> &position) = 0;

            [[nodiscard]] virtual LightType getType() const = 0;
            [[nodiscard]] virtual std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const = 0;

    }; // ILights

} // namespace RayTracer

#endif //RAYTRACER_ILIGHTS_HPP

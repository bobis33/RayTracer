/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShapes.cpp
*/

#ifndef RAYTRACER_ISHAPES_HPP
#define RAYTRACER_ISHAPES_HPP

#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class IShapes {

        public:
            virtual ~IShapes() = default;

            virtual void setType(const ShapeType& type) = 0;
            virtual void setColor(const std::tuple<uint8_t, uint8_t, uint8_t>& color) = 0;
            virtual void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t>& position) = 0;
            virtual void setRadius(float radius) = 0;

            [[nodiscard]] virtual ShapeType getType() const = 0;
            [[nodiscard]] virtual std::tuple<uint8_t, uint8_t, uint8_t> getColor() const = 0;
            [[nodiscard]] virtual std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const = 0;
            [[nodiscard]] virtual float getRadius() const = 0;

    }; // IShapes

} // namespace RayTracer

#endif //RAYTRACER_ISHAPES_HPP

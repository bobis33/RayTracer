/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AShapes.cpp
*/

#ifndef RAYTRACER_ASHAPES_HPP
#define RAYTRACER_ASHAPES_HPP

#include <cstdint>
#include <string>
#include <tuple>

#include "RayTracer/Abstraction/IShapes.hpp"

namespace RayTracer {

    enum class ShapeType : uint8_t {
        SPHERE,
        PLANE,
        CYLINDER,
        CONE,
        NONE
    };

    class AShapes : public IShapes {

        public:
            ~AShapes() override = default;

            void setType(const ShapeType& type) { m_type = type; };
            void setColor(const std::tuple<uint8_t, uint8_t, uint8_t>& color) { m_color = color; };
            void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t>& position) { m_position = position; };

            [[nodiscard]] ShapeType getType() const { return m_type; };
            [[nodiscard]] std::tuple<uint8_t, uint8_t, uint8_t> getColor() const { return m_color; };
            [[nodiscard]] std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const { return m_position; };

        private:
            ShapeType m_type{ShapeType::NONE};
            std::tuple<uint8_t, uint8_t, uint8_t> m_color{0, 0, 0};
            std::tuple<uint16_t, uint16_t, uint16_t> m_position{0, 0, 0};

    }; // class AShapes

} // namespace RayTracer

#endif //RAYTRACER_ASHAPES_HPP

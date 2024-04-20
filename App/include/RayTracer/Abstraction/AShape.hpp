/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AShape.cpp
*/

#ifndef RAYTRACER_ASHAPE_HPP
#define RAYTRACER_ASHAPE_HPP

#include <cstdint>
#include <string>
#include <tuple>

#include "RayTracer/Abstraction/IShape.hpp"

namespace RayTracer {

    class AShape : public IShape {

        public:
            ~AShape() override = default;

            void setType(const ShapeType& type) override { m_type = type; };
            void setColor(const std::tuple<uint8_t, uint8_t, uint8_t>& color) override { m_color = color; };
            void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t>& position) override { m_position = position; };
            void setRadius(float radius) override { m_radius = radius; };

            [[nodiscard]] ShapeType getType() const override { return m_type; };
            [[nodiscard]] std::tuple<uint8_t, uint8_t, uint8_t> getColor() const override { return m_color; };
            [[nodiscard]] std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const override { return m_position; };
            [[nodiscard]] float getRadius() const override { return m_radius; };

        private:
            ShapeType m_type{ShapeType::NONE};
            std::tuple<uint8_t, uint8_t, uint8_t> m_color{0, 0, 0};
            std::tuple<uint16_t, uint16_t, uint16_t> m_position{0, 0, 0};
            float m_radius{0};

    }; // class AShape

} // namespace RayTracer

#endif //RAYTRACER_ASHAPE_HPP

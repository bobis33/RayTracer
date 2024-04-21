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
            void setRadius(float radius) override { m_radius = radius; };

            [[nodiscard]] ShapeType getType() const override { return m_type; };
            [[nodiscard]] RGBColor getColor() const override { return m_color; };
            [[nodiscard]] Position getPosition() const override { return m_position; };
            [[nodiscard]] float getRadius() const override { return m_radius; };

        private:
            ShapeType m_type{ShapeType::NONE};
            RGBColor m_color{0, 0, 0};
            Position m_position{0, 0, 0};
            float m_radius{0};

    }; // class AShape

} // namespace RayTracer

#endif //RAYTRACER_ASHAPE_HPP

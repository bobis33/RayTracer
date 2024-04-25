/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AShape.cpp
*/

#ifndef RAYTRACER_ASHAPE_HPP
#define RAYTRACER_ASHAPE_HPP

#include "RayTracer/Abstraction/IShape.hpp"

namespace RayTracer {

    class AShape : public IShape {

        public:
            ~AShape() override = default;

            void setType(const ShapeType &type) override { m_type = type; };
            void setRadius(float radius) override { m_radius = radius; };
            void setMaterial(std::unique_ptr<AMaterial> material) override { m_material = std::move(material); };

            [[nodiscard]] ShapeType getType() const override { return m_type; };
            [[nodiscard]] AMaterial* getMaterial() const override { return m_material.get(); };
            [[nodiscard]] Position& getPosition() override { return m_position; };
            [[nodiscard]] float getRadius() const override { return m_radius; };

        private:
            ShapeType m_type{ShapeType::NONE};
            std::unique_ptr<AMaterial> m_material;
            Position m_position{0, 0, 0};
            float m_radius{0};

    }; // class AShape

} // namespace RayTracer

#endif //RAYTRACER_ASHAPE_HPP

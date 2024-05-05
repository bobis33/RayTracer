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
            void setRadius(const int16_t& radius) override { m_radius = radius; };
            void setMaterial(std::unique_ptr<AMaterial> material) override { m_material = std::move(material); };

            [[nodiscard]] const ShapeType& getType() const override { return m_type; };
            [[nodiscard]] const AMaterial& getMaterial() const override { return *m_material; };
            [[nodiscard]] Vector& getPosition() override { return m_position; };
            [[nodiscard]] Vector& getRotation() override { return m_position; };
            [[nodiscard]] int16_t getRadius() const override { return m_radius; };

        private:
            ShapeType m_type{ShapeType::NONE};
            std::unique_ptr<AMaterial> m_material;
            Vector m_position{0, 0, 0};
            Vector m_rotation{0, 0, 0};
            int16_t m_radius{0};

    }; // class AShape

} // namespace RayTracer

#endif //RAYTRACER_ASHAPE_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AShape.cpp
*/

#ifndef RAYTRACER_ASHAPE_HPP
#define RAYTRACER_ASHAPE_HPP

#include "RayTracer/Abstraction/IShape.hpp"

namespace rtr {

    class AShape : public IShape {

        public:

            ~AShape() override = default;

            void setType(const ShapeType &type) override { m_type = type; };
            void setRadius(const double& radius) override { m_radius = radius; };
            void setHeight(const double& height) override { m_height = height; };
            void setMaterial(std::unique_ptr<AMaterial> material) override { m_material = std::move(material); };

            [[nodiscard]] const ShapeType& getType() const override { return m_type; };
            [[nodiscard]] AMaterial& getMaterial() override { return *m_material; };
            [[nodiscard]] Vector& getPosition() override { return m_position; };
            [[nodiscard]] Vector& getNormal() override { return m_normal; };
            [[nodiscard]] Vector& getRotation() override { return m_rotation; };
            [[nodiscard]] const double &getRadius() const override { return m_radius; };
            [[nodiscard]] const double &getHeight() const override { return m_height; };

            [[nodiscard]] Vector getDistance(const Vector& point) override { return point - m_position; };

        private:

            ShapeType m_type{ShapeType::NONE};
            std::unique_ptr<AMaterial> m_material;
            Vector m_position{0, 0, 0};
            Vector m_normal{0, 0, 0};
            Vector m_rotation{0, 0, 0};
            double m_radius{0};
            double m_height{0};

    }; // class AShape

} // namespace RayTracer

#endif //RAYTRACER_ASHAPE_HPP

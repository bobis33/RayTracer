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
            void setRadius(const double& radius) override { m_radius = radius; };
            void setMaterial(std::unique_ptr<AMaterial> material) override { m_material = std::move(material); };

            [[nodiscard]] const ShapeType& getType() const override { return m_type; };
            [[nodiscard]] AMaterial& getMaterial() override { return *m_material; };
            [[nodiscard]] Vector& getPosition() override { return m_position; };
            [[nodiscard]] Vector& getRotation() override { return m_position; };
            [[nodiscard]] double getRadius() const override { return m_radius; };

            [[nodiscard]] bool hits(std::pair<Vector, Vector> ray) override {
                Vector vec = ray.first - m_position;
                double a = ray.second.dot(ray.second);
                double b = 2 * vec.dot(ray.second);
                double c = vec.dot(vec) - static_cast<double>(m_radius) * static_cast<double>(m_radius);
                double discriminant = b * b - 4 * a * c;

                return discriminant > 0;
            }

        private:
            ShapeType m_type{ShapeType::NONE};
            std::unique_ptr<AMaterial> m_material;
            Vector m_position{0, 0, 0};
            Vector m_rotation{0, 0, 0};
            double m_radius{0};

    }; // class AShape

} // namespace RayTracer

#endif //RAYTRACER_ASHAPE_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ARenderer.cpp
*/

#ifndef RAYTRACER_ARENDERER_HPP
#define RAYTRACER_ARENDERER_HPP

#include "RayTracer/Abstraction/IRenderer.hpp"

namespace RayTracer {

    class ARenderer : public IRenderer {

        public:
            ~ARenderer() override = default;

            void setType(const RendererType &rendererType) override { m_type = rendererType; };
            void setName(const std::string &name) override { m_name = name; };

            [[nodiscard]] const RendererType& getType() const override { return m_type; };
            [[nodiscard]] Resolution& getResolution() override { return m_resolution; };
            [[nodiscard]] Color& getBackgroundColor() override { return m_backgroundColor; };
            [[nodiscard]] const std::string& getName() const override { return m_name; };
            [[nodiscard]] std::vector<std::vector<RayTracer::Color>>& getPixels() override { return m_pixels; };
            void setPixels(const std::vector<std::vector<RayTracer::Color>>& pixels) override { m_pixels = pixels; };

        private:
            RendererType m_type{RendererType::NONE};
            Resolution m_resolution{1920, 1080};
            std::string m_name{"Default Renderer Name"};
            Color m_backgroundColor{Color::getBlack()};
            std::vector<std::vector<RayTracer::Color>> m_pixels;

    }; // class ARenderer

    class Ray {
    public:
        RayTracer::Vector m_origin;
        RayTracer::Vector m_direction;

        Ray() = default;
        Ray(const RayTracer::Vector& origin, const RayTracer::Vector& direction)
            : m_origin(origin), m_direction(direction) {};
    };

    class Sphere {
    public:
        RayTracer::Vector m_center;
        double m_radius;

        Sphere(const RayTracer::Vector& center, double radius)
            : m_center(center), m_radius(radius) {}

        [[nodiscard]] bool hits(const Ray& ray) const {
            RayTracer::Vector oc(m_center.getX() - ray.m_origin.getX(), m_center.getY() - ray.m_origin.getY(), m_center.getZ() - ray.m_origin.getZ());
            double a = ray.m_direction.dot(ray.m_direction);
            double b = 2 * oc.dot(ray.m_direction);
            double c = oc.dot(oc) - m_radius * m_radius;
            double discriminant = b * b - 4 * a * c;

            return discriminant >= 0;
        }
    };

    class Plane {
    public:
        RayTracer::Vector m_point;
        RayTracer::Vector m_normal;

        Plane(const RayTracer::Vector& point, const RayTracer::Vector& normal)
            : m_point(point), m_normal(normal) {}

        [[nodiscard]] bool hits(const Ray& ray) const {
            double denominator = m_normal.dot(ray.m_direction);
            if (denominator == 0) {
                return false;
            }

            double t = m_normal.dot(RayTracer::Vector(m_point.getX() - ray.m_origin.getX(), m_point.getY() - ray.m_origin.getY(), m_point.getZ() - ray.m_origin.getZ())) / denominator;
            return t >= 0;
        }
    };

    class Cameraa {
    public:
        RayTracer::Vector m_origin, m_direction;
        RayTracer::Rectangle3D m_screen;

        Cameraa(const RayTracer::Vector& origin, const RayTracer::Rectangle3D& screen, const RayTracer::Vector& direction)
            : m_origin(origin), m_direction(direction), m_screen(screen) {}

        Ray ray(int16_t u, int16_t v) const {
            RayTracer::Vector point = m_screen.pointAt(u, v);
            return Ray(m_origin, RayTracer::Vector(point.getX() - m_origin.getX(), point.getY() - m_origin.getY(), point.getZ() - m_origin.getZ()) + m_direction);
        }
    };

} // namespace RayTracer

#endif //RAYTRACER_ARENDERER_HPP

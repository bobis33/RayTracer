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

        private:
            RendererType m_type{RendererType::NONE};
            Resolution m_resolution{1920, 1080};
            std::string m_name{"Default Renderer Name"};
            Color m_backgroundColor{Color::getBlack()};

    }; // class ARenderer

    class Ray {
    public:
        RayTracer::Point3D origin;
        RayTracer::Vector3D direction;

        Ray() : origin(), direction() {}
        Ray(const RayTracer::Point3D& origin, const RayTracer::Vector3D& direction)
            : origin(origin), direction(direction) {}
    };

    class Sphere {
    public:
        RayTracer::Point3D center;
        double radius;

        Sphere(const RayTracer::Point3D& center, double radius)
            : center(center), radius(radius) {}

        bool hits(const Ray& ray) const {
            RayTracer::Vector3D oc(center.x - ray.origin.x, center.y - ray.origin.y, center.z - ray.origin.z);
            double a = ray.direction.dot(ray.direction);
            double b = 2 * oc.dot(ray.direction);
            double c = oc.dot(oc) - radius * radius;
            double discriminant = b * b - 4 * a * c;

            return discriminant >= 0;
        }
    };

    class Plane {
    public:
        RayTracer::Point3D point;
        RayTracer::Vector3D normal;

        Plane(const RayTracer::Point3D& point, const RayTracer::Vector3D& normal)
            : point(point), normal(normal) {}

        bool hits(const Ray& ray) const {
            double denominator = normal.dot(ray.direction);
            if (denominator == 0) {
                return false;
            }

            double t = normal.dot(RayTracer::Vector3D(point.x - ray.origin.x, point.y - ray.origin.y, point.z - ray.origin.z)) / denominator;
            if (t < 0) {
                return false;
            }

            return true;
        }
    };

    class Cameraa {
    public:
        RayTracer::Point3D origin;
        RayTracer::Rectangle3D screen;
        RayTracer::Vector3D direction;

        Cameraa(const RayTracer::Point3D& origin, const RayTracer::Rectangle3D& screen, const RayTracer::Vector3D& direction)
            : origin(origin), screen(screen), direction(direction) {}

        Ray ray(double u, double v) const {
            RayTracer::Point3D point = screen.pointAt(u, v);
            return Ray(origin, RayTracer::Vector3D(point.x - origin.x, point.y - origin.y, point.z - origin.z) + direction);
        }
    };

} // namespace RayTracer

#endif //RAYTRACER_ARENDERER_HPP

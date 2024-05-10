/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** RayHit
*/

#ifndef RAYTRACER_RAY_HIT_HPP
#define RAYTRACER_RAY_HIT_HPP

#include "RayTracer/Utils/Vector.hpp"

namespace rtr {

    using ray_hit_t = struct ray_hit_s {
        Vector point;
        Vector normal;
        double distance;
    };

    class RayHit {

        public:

            [[nodiscard]] const ray_hit_t &getRayHit() const noexcept { return m_rayHit; };

            void setRayHit(const ray_hit_t &ray_hit) noexcept { m_rayHit = ray_hit; };
            void setRayHit(const Vector &point, const Vector &normal, double distance) noexcept {
                m_rayHit.point = point;
                m_rayHit.normal = normal;
                m_rayHit.distance = distance;
            };
            void setPoint(const Vector &point) noexcept { m_rayHit.point = point; };
            void setNormal(const Vector &normal) noexcept { m_rayHit.normal = normal; };
            void setDistance(const double &distance) noexcept { m_rayHit.distance = distance; };

        private:

            ray_hit_t m_rayHit;

    }; // class RayHit

} // namespace RayTracer

#endif // RAYTRACER_RAY_HIT_HPP

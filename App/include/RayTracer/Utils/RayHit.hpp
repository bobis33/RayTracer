/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** RayHit
*/

/// @file RayHit.hpp
#ifndef RAYTRACER_RAY_HIT_HPP
#define RAYTRACER_RAY_HIT_HPP

#include "RayTracer/Utils/Vector.hpp"

namespace rtr {

    /// @struct ray_hit_s RayHit.hpp
    /// @brief A struct representing a ray hit in 3D space.
    /// @brief Type alias for a ray hit.
    using ray_hit_t = struct ray_hit_s {
        /// @brief The point of intersection between the ray and the object.
        Vector point;
        /// @brief The normal vector at the point of intersection.
        Vector normal;
        /// @brief The distance from the ray origin to the point of intersection.
        double distance;
    };

    /// @class RayHit
    /// @brief A class representing a ray hit in 3D space.
    class RayHit {

        public:

            [[nodiscard]] const ray_hit_t &getRayHit() const noexcept { return m_rayHit; };

            /// @brief Sets the ray hit data.
            /// @param ray_hit The ray hit data to set
            void setRayHit(const ray_hit_t &ray_hit) noexcept { m_rayHit = ray_hit; };

            /// @brief Sets the ray hit data.
            /// @param point The point of intersection.
            /// @param normal The normal vector at the point of intersection.
            /// @param distance The distance from the ray origin to the point of intersection.
            void setRayHit(const Vector &point, const Vector &normal, const double &distance) noexcept {
                m_rayHit.point = point;
                m_rayHit.normal = normal;
                m_rayHit.distance = distance;
            };

            /// @brief Sets the point of intersection.
            /// @param point The point of intersection to set.
            void setPoint(const Vector &point) noexcept { m_rayHit.point = point; };

            /// @brief Sets the normal vector at the point of intersection.
            /// @param normal The normal vector to set.
            void setNormal(const Vector &normal) noexcept { m_rayHit.normal = normal; };

            /// @brief Sets the distance from the ray origin to the point of intersection.
            /// @param distance The distance to set.
            void setDistance(const double &distance) noexcept { m_rayHit.distance = distance; };

        private:

            /// @brief The ray hit data.
            ray_hit_t m_rayHit;

    }; // class RayHit

} // namespace RayTracer

#endif // RAYTRACER_RAY_HIT_HPP

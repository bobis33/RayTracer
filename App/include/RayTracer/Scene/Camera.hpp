/*
** EPITECH PROJECT, 2024
** Raytracer | Camera
** File description:
** Camera.hpp
*/

/// @file Camera.hpp
#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "RayTracer/Utils/Vector.hpp"

namespace rtr {

    /// @class Camera
    /// @brief A class to handle the camera.
    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;
            Camera(uint16_t fov, const Vector &origin, const Vector &direction);

            /// @brief Sets the camera's field of view.
            /// @param fov The field of view, as a uint16, or a unsigned short.
            void setFov(const uint16_t fov) { m_fov = fov; };

            /// @brief Gets the camera's field of view.
            /// @return The field of view, as a uint16, or a unsigned short.
            [[nodiscard]] uint16_t getFov() const { return m_fov; };

            /// @brief Gets the camera's origin.
            [[nodiscard]] const Vector &getOrigin() const { return m_origin; };

            /// @brief Gets the camera's direction.
            [[nodiscard]] const Vector &getDirection() const { return m_direction; };

            /// @brief Gets the camera's up vector.
            [[nodiscard]] const Vector &getUp() const { return m_up; };

            /// @brief The camera's ray, used to check if the ray intersects with an object.
            /// @param u defines the horizontal position of the ray.
            /// @param v defines the vertical position of the ray.
            /// @return A pair of vectors that defines the origin of the ray and its normal.
            [[nodiscard]] std::pair<Vector, Vector> ray(const double u, const double v) const {
                return {m_origin, (m_lowerLeftCorner + m_horizontal * u + m_vertical * v - m_origin).normalize()};
            }

        private:
            /// @brief The camera's field of view.
            uint16_t m_fov{0};

            /// @brief The camera's origin.
            Vector m_origin{0, 0, 0};

            /// @brief The camera's direction.
            Vector m_direction{0, 0, 0};

            /// @brief The camera's up vector.
            Vector m_up{0, 1, 0};

            /// @brief The camera's aspect ratio.
            double m_aspectRatio{1.77777778};

            /// @brief The camera's horizontal vector.
            Vector m_horizontal, m_vertical, m_lowerLeftCorner;

            /// @brief The camera's u, v and w vectors.
            Vector m_u, m_v, m_w;

    }; // class Camera

} // namespace RayTracer

#endif //RAYTRACER_CAMERA_HPP

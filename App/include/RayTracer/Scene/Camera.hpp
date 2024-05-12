/*
** EPITECH PROJECT, 2024
** Raytracer | Camera
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "RayTracer/Utils/Vector.hpp"

namespace rtr {

    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;
            Camera(uint16_t fov, const Vector &origin, const Vector &direction);

            void setFov(const uint16_t fov) { m_fov = fov; };

            [[nodiscard]] uint16_t getFov() const { return m_fov; };
            [[nodiscard]] const Vector &getOrigin() const { return m_origin; };
            [[nodiscard]] const Vector &getDirection() const { return m_direction; };
            [[nodiscard]] const Vector &getUp() const { return m_up; };

            [[nodiscard]] std::pair<Vector, Vector> ray(const double u, const double v) const {
                return {m_origin, (m_lowerLeftCorner + m_horizontal * u + m_vertical * v - m_origin).normalize()};
            }

        private:
            uint16_t m_fov{0};
            Vector m_origin{0, 0, 0};
            Vector m_direction{0, 0, 0};
            Vector m_up{0, 1, 0};
            double m_aspectRatio{1.77777778};
            Vector m_horizontal, m_vertical, m_lowerLeftCorner;
            Vector m_u, m_v, m_w;

    }; // class Camera

} // namespace RayTracer

#endif //RAYTRACER_CAMERA_HPP

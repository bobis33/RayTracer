/*
** EPITECH PROJECT, 2024
** Raytracer | Camera
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "RayTracer/Utils/Vector.hpp"

namespace RayTracer {

    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;
            Camera(uint16_t fov, Vector position, Vector direction, Vector up)
                : m_fov(fov), m_origin(position), m_direction(direction), m_up(up) {};

            void setFov(const uint16_t &fov) { m_fov = fov; };

            [[nodiscard]] const uint16_t &getFov() const { return m_fov; };
            [[nodiscard]] const Vector &getOrigin() const { return m_origin; };
            [[nodiscard]] const Vector &getDirection() const { return m_direction; };
            [[nodiscard]] const Vector &getUp() const { return m_up; };

        private:
            uint16_t m_fov{0};
            Vector m_origin{0, 0, 0};
            Vector m_direction{0, 0, -1};
            Vector m_up{0, 1, 0};

    }; // class Camera

} // namespace RayTracer

#endif //RAYTRACER_CAMERA_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Camera
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "RayTracer/Position.hpp"

namespace RayTracer {

    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;

            void setFov(const uint16_t &fov) { m_fov = fov; };

            [[nodiscard]] uint16_t getFov() const { return m_fov; };
            [[nodiscard]] Position getPosition() const { return m_position; };

        private:
            uint16_t m_fov{0};
            Position m_position{0, 0, 0};

    }; // class Camera

} // namespace RayTracer

#endif //RAYTRACER_CAMERA_HPP

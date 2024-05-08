/*
** EPITECH PROJECT, 2024
** Raytracer | Camera
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

#include "RayTracer/Utils/Vector.hpp"
#include "RayTracer/Utils/Rectangle3D.hpp"

namespace RayTracer {

    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;
            Camera(uint16_t fov, Vector origin, Vector direction)
                : m_fov{fov}, m_origin{origin}, m_direction{direction} {};

            void setFov(const uint16_t &fov) { m_fov = fov; };
            void setCameraScreen(const Rectangle3D &cameraScreen) { m_cameraScreen = cameraScreen; };

            [[nodiscard]] const uint16_t &getFov() const { return m_fov; };
            [[nodiscard]] const Vector &getOrigin() const { return m_origin; };
            [[nodiscard]] const Vector &getDirection() const { return m_direction; };
            [[nodiscard]] const Rectangle3D &getCameraScreen() const { return m_cameraScreen; };

            [[nodiscard]] std::pair<Vector, Vector> ray(double u, double v) const {
                Vector point{m_cameraScreen.pointAt(u, v)};
                return std::make_pair(m_origin, Vector{point.getX() - m_origin.getX(), point.getY() - m_origin.getY(), point.getZ() - m_origin.getZ()} + m_direction);
            }

        private:
            uint16_t m_fov{0};
            Vector m_origin{0, 0, 0};
            Vector m_direction{0, 0, 0};
            Rectangle3D m_cameraScreen{{0, 0, 0},{0, 0, 0},{0, 0, 0}};

    }; // class Camera

} // namespace RayTracer

#endif //RAYTRACER_CAMERA_HPP

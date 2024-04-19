/*
** EPITECH PROJECT, 2024
** Raytracer | Camera
** File description:
** Camera.hpp
*/

#ifndef RAYTRACER_CAMERA_HPP
#define RAYTRACER_CAMERA_HPP

namespace RayTracer {

    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;

            void setFov(uint16_t fov) { m_fov = fov; };
            void setPosition(std::tuple<uint16_t, uint16_t, uint16_t> position) { m_position = position; };

            [[nodiscard]] uint16_t getFov() const { return m_fov; };
            [[nodiscard]] std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const { return m_position; };

        private:
            uint16_t m_fov{0};
            std::tuple<uint16_t, uint16_t, uint16_t> m_position{0, 0, 0};

    }; // class Camera

} // namespace RayTracer

#endif //RAYTRACER_CAMERA_HPP

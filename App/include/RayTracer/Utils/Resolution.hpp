/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Resolution
*/

#ifndef RAYTRACER_RESOLUTION_HPP
#define RAYTRACER_RESOLUTION_HPP

#include <cstdint>

namespace RayTracer {

    using resolution_t = struct Resolution_s {
        uint16_t width;
        uint16_t height;
    };

    class Resolution {

        public:
            Resolution() : m_resolution(1920, 1080) {};
            Resolution(const uint16_t &width, const uint16_t &height) : m_resolution(width, height) {};
            explicit Resolution(const resolution_t &resolution) : m_resolution(resolution) {};
            ~Resolution() = default;

            void setWidth(const uint16_t &width) { m_resolution.width = width; };
            void setHeight(const uint16_t &height) { m_resolution.height = height; };
            void setResolution(const uint16_t &width, const uint16_t &height) { m_resolution = {width, height}; };
            void setResolution(const resolution_t &resolution) { m_resolution = resolution; };

            [[nodiscard]] uint16_t getWidth() const { return m_resolution.width; }
            [[nodiscard]] uint16_t getHeight() const { return m_resolution.height; }
            [[nodiscard]] resolution_t getValue() const { return m_resolution; };

        private:
            resolution_t m_resolution{0, 0};


    }; // class Resolution

}; // namespace RayTracer

#endif //RAYTRACER_RESOLUTION_HPP

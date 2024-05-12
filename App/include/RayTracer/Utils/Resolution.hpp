/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Resolution
*/

/// @file Resolution.hpp
#ifndef RAYTRACER_RESOLUTION_HPP
#define RAYTRACER_RESOLUTION_HPP

#include <cstdint>

namespace rtr {

    /// @struct resolution_s Resolution.hpp
    /// @brief A struct representing the resolution of an image.
    /// @brief Type alias for the resolution of an image.
    using resolution_t = struct resolution_s {
        /// @brief The width of the image.
        uint16_t width;
        /// @brief The height of the image.
        uint16_t height;
    };

    /// @class Resolution
    /// @brief Class representing the resolution of an image.
    class Resolution {

        public:
            Resolution() : m_resolution{1920, 1080} {};
            Resolution(const uint16_t &width, const uint16_t &height) : m_resolution{width, height} {};
            explicit Resolution(const resolution_t &resolution) : m_resolution{resolution} {};
            ~Resolution() = default;

            /// @brief Sets the width of the resolution.
            /// @param width The width to set.
            void setWidth(const uint16_t &width) { m_resolution.width = width; };

            /// @brief Sets the height of the resolution.
            /// @param height The height to set.
            void setHeight(const uint16_t &height) { m_resolution.height = height; };

            /// @brief Sets the resolution to the given width and height.
            /// @param width The width of the resolution.
            /// @param height The height of the resolution.
            void setResolution(const uint16_t &width, const uint16_t &height) { m_resolution = {width, height}; };

            /// @brief Sets the resolution to the given resolution struct.
            /// @param resolution The resolution struct to set.
            void setResolution(const resolution_t &resolution) { m_resolution = resolution; };

            /// @brief Gets the width of the resolution.
            /// @return The width of the resolution.
            [[nodiscard]] uint16_t getWidth() const { return m_resolution.width; }

            /// @brief Gets the height of the resolution.
            /// @return The height of the resolution.
            [[nodiscard]] uint16_t getHeight() const { return m_resolution.height; }

            /// @brief Gets the resolution as a struct.
            /// @return The resolution struct.
            [[nodiscard]] resolution_t getValue() const { return m_resolution; };

        private:

            /// @brief The resolution of the image.
            resolution_t m_resolution{0, 0};

    }; // class Resolution

}; // namespace RayTracer

#endif //RAYTRACER_RESOLUTION_HPP

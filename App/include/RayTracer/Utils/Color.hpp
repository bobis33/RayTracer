/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Color.hpp
*/

/// @file Color.hpp
#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

#include <cstdint>

/// @brief Maximum value for RGB color components.
static constexpr int RGB_MAX = 255;

/// @brief Half of the maximum value for RGB color components.
static constexpr int RGB_HALF = 128;

namespace rtr {

    /// @struct color_s Color.hpp
    /// @brief A struct representing an RGB color.
    /// @brief Type alias for an RGB color component.
    using color_t = struct color_s {
        /// @brief Red color component.
        uint8_t r{0};
        /// @brief Green color component.
        uint8_t g{0};
        /// @brief Blue color component.
        uint8_t b{0};
    };

    /// @class Color
    /// @brief Class representing RGB colors.
    class Color {

        public:

            Color() : m_color{0, 0, 0} {};
            Color(const uint8_t r, const uint8_t g, const uint8_t b) : m_color{r, g, b} {};
            explicit Color(const color_t &color) : m_color{color} {};
            ~Color() = default;

            /// @brief Sets the color components.
            /// @param r Red color component.
            /// @param g Green color component.
            /// @param b Blue color component.
            void setColor(const uint8_t r, const uint8_t g, const uint8_t b) { m_color = {r, g, b}; };

            /// @brief Sets the color components.
            /// @param color An RGB color.
            void setColor(const color_t &color) { m_color = color; };
            void setR(const uint8_t r) { m_color.r = r; };
            void setG(const uint8_t g) { m_color.g = g; };
            void setB(const uint8_t b) { m_color.b = b; };

            [[nodiscard]] color_t getValue() const { return m_color; };
            [[nodiscard]] uint8_t getR() const { return m_color.r; };
            [[nodiscard]] uint8_t getG() const { return m_color.g; };
            [[nodiscard]] uint8_t getB() const { return m_color.b; };

            static constexpr color_t getRed() { return color_t{RGB_MAX, 0, 0}; };
            static constexpr color_t getGreen() { return color_t{0, RGB_MAX, 0}; };
            static constexpr color_t getBlue() { return color_t{0, 0, RGB_MAX}; };
            static constexpr color_t getWhite() { return color_t{RGB_MAX, RGB_MAX, RGB_MAX}; };
            static constexpr color_t getBlack() { return color_t{0, 0, 0}; };
            static constexpr color_t getYellow() { return color_t{RGB_MAX, RGB_MAX, 0}; };
            static constexpr color_t getMagenta() { return color_t{RGB_MAX, 0, RGB_MAX}; };
            static constexpr color_t getCyan() { return color_t{0, RGB_MAX, RGB_MAX}; };
            static constexpr color_t getGray() { return color_t{RGB_HALF, RGB_HALF, RGB_HALF}; };
            static constexpr color_t getOrange() { return color_t{RGB_MAX, 165, 0}; };
            static constexpr color_t getBrown() { return color_t{165, 42, 42}; };

            static constexpr color_t getLightBlue() { return color_t{173, 216, 230}; };
            static constexpr color_t getLightGreen() { return color_t{144, 238, 144}; };
            static constexpr color_t getLightPink() { return color_t{RGB_MAX, 182, 193}; };
            static constexpr color_t getLightYellow() { return color_t{RGB_MAX, RGB_MAX, 224}; };
            static constexpr color_t getLightGray() { return color_t{211, 211, 211}; };

            static constexpr color_t getDarkGray() { return color_t{169, 169, 169}; };
            static constexpr color_t getDarkRed() { return color_t{139, 0, 0}; };
            static constexpr color_t getDarkGreen() { return color_t{0, 100, 0}; };
            static constexpr color_t getDarkBlue() { return color_t{0, 0, 139}; };
            static constexpr color_t getDarkYellow() { return color_t{139, 139, 0}; };

            /// @brief Adds two colors.
            /// @param other The other color to add.
            /// @return The sum of the two colors.
            Color operator+(const Color &other) const {
                return {
                    static_cast<uint8_t>(m_color.r + other.getValue().r),
                    static_cast<uint8_t>(m_color.g + other.getValue().g),
                    static_cast<uint8_t>(m_color.b + other.getValue().b)
                };
            };

            /// @brief Multiplies a color by a scalar.
            /// @param scalar The scalar to multiply by.
            /// @return The product of the color and the scalar.
            Color operator*(const double &scalar) const {
                return {
                    static_cast<uint8_t>(m_color.r * scalar),
                    static_cast<uint8_t>(m_color.g * scalar),
                    static_cast<uint8_t>(m_color.b * scalar)
                };
            };

            /// @brief Multiplies two colors.
            /// @param other The other color to multiply.
            /// @return The product of the two colors.
            Color operator*(const Color &other) const {
                return {
                    static_cast<uint8_t>(m_color.r * other.getValue().r),
                    static_cast<uint8_t>(m_color.g * other.getValue().g),
                    static_cast<uint8_t>(m_color.b * other.getValue().b)
                };
            };

            /// @brief Adds a color to the current color.
            /// @param other The other color to add.
            /// @return A reference to the current color.
            Color operator+=(const Color &other) {
                m_color = {
                    static_cast<uint8_t>(m_color.r + other.getValue().r),
                    static_cast<uint8_t>(m_color.g + other.getValue().g),
                    static_cast<uint8_t>(m_color.b + other.getValue().b)
                };
                return *this;
            };

            /// @brief Multiplies the current color by a scalar.
            /// @param scalar The scalar to multiply by.
            /// @return A reference to the current color.
            Color operator*=(const double &scalar) {
                m_color = {
                    static_cast<uint8_t>(m_color.r * scalar),
                    static_cast<uint8_t>(m_color.g * scalar),
                    static_cast<uint8_t>(m_color.b * scalar)
                };
                return *this;
            };

        private:

            /// @brief The RGB color components.
            color_t m_color{0, 0, 0};

    }; // class Color

} // namespace RayTracer

#endif // RAYTRACER_COLOR_HPP

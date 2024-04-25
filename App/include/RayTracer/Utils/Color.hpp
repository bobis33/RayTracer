/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** RGBColor.hpp
*/

#ifndef RAYTRACER_RGB_COLOR_HPP
#define RAYTRACER_RGB_COLOR_HPP

#include <cstdint>

static constexpr int RGB_MAX = 255;
static constexpr int RGB_HALF = 128;

namespace RayTracer {

    using color_t = struct Color_s {
        uint8_t r{0};
        uint8_t g{0};
        uint8_t b{0};
    };

    class Color {

        public:

            Color() : m_color(0, 0, 0) {};
            Color(const uint8_t &r, const uint8_t &g, const uint8_t &b) : m_color(r, g, b) {};
            explicit Color(const color_t &color) : m_color(color) {};
            ~Color() = default;

            void setColor(const uint8_t &r, const uint8_t &g, const uint8_t &b) { m_color = {r, g, b}; };
            void setColor(const color_t &color) { m_color = color; };
            [[nodiscard]] color_t getValue() const { return m_color; };

            static color_t customColor(const uint8_t &r, const uint8_t &g, const uint8_t &b) { return color_t{r, g, b}; };

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

        private:
            color_t m_color{0, 0, 0};

    }; // class RGBColor

} // namespace RayTracer

#endif // RAYTRACER_RGB_COLOR_HPP

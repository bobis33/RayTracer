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

    using Color_t = struct Color_s {
        uint8_t r{0};
        uint8_t g{0};
        uint8_t b{0};
    };

    class RGBColor {

        public:

            RGBColor() : m_color({0, 0, 0}) {};
            RGBColor(const uint8_t &r, const uint8_t &g, const uint8_t &b) : m_color(r, g, b) {};
            explicit RGBColor(const Color_t &color) : m_color(color) {};
            ~RGBColor() = default;

            void setColor(const uint8_t &r, const uint8_t &g, const uint8_t &b) { m_color = {r, g, b}; };
            void setColor(const Color_t &color) { m_color = color; };
            [[nodiscard]] Color_t getColor() const { return m_color; };

            static Color_t customColor(const uint8_t &r, const uint8_t &g, const uint8_t &b) { return Color_t{r, g, b}; };

            static Color_t getRed() { return Color_t{RGB_MAX, 0, 0}; };
            static Color_t getGreen() { return Color_t{0, RGB_MAX, 0}; };
            static Color_t getBlue() { return Color_t{0, 0, RGB_MAX}; };
            static Color_t getWhite() { return Color_t{RGB_MAX, RGB_MAX, RGB_MAX}; };
            static Color_t getBlack() { return Color_t{0, 0, 0}; };
            static Color_t getYellow() { return Color_t{RGB_MAX, RGB_MAX, 0}; };
            static Color_t getMagenta() { return Color_t{RGB_MAX, 0, RGB_MAX}; };
            static Color_t getCyan() { return Color_t{0, RGB_MAX, RGB_MAX}; };
            static Color_t getGray() { return Color_t{RGB_HALF, RGB_HALF, RGB_HALF}; };
            static Color_t getOrange() { return Color_t{RGB_MAX, 165, 0}; };
            static Color_t getBrown() { return Color_t{165, 42, 42}; };

            static Color_t getLightBlue() { return Color_t{173, 216, 230}; };
            static Color_t getLightGreen() { return Color_t{144, 238, 144}; };
            static Color_t getLightPink() { return Color_t{RGB_MAX, 182, 193}; };
            static Color_t getLightYellow() { return Color_t{RGB_MAX, RGB_MAX, 224}; };
            static Color_t getLightGray() { return Color_t{211, 211, 211}; };

            static Color_t getDarkGray() { return Color_t{169, 169, 169}; };
            static Color_t getDarkRed() { return Color_t{139, 0, 0}; };
            static Color_t getDarkGreen() { return Color_t{0, 100, 0}; };
            static Color_t getDarkBlue() { return Color_t{0, 0, 139}; };
            static Color_t getDarkYellow() { return Color_t{139, 139, 0}; };

        private:
            Color_t m_color{0, 0, 0};

    }; // class RGBColor

} // namespace RayTracer

#endif // RAYTRACER_RGB_COLOR_HPP

/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** FlatColor
*/

#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

#include <cstdint>

namespace RayTracer {

    using Color_t = struct Color_s {
        uint8_t r{0};
        uint8_t g{0};
        uint8_t b{0};
    };

    class Color {

        public:
            static Color_t getRed() { return {255, 0, 0}; };
            static Color_t getGreen() { return {0, 255, 0}; };
            static Color_t getBlue() { return {0, 0, 255}; };
            static Color_t getWhite() { return {255, 255, 255}; };
            static Color_t getBlack() { return {0, 0, 0}; };
            static Color_t getYellow() { return {255, 255, 0}; };
            static Color_t getMagenta() { return {255, 0, 255}; };
            static Color_t getCyan() { return {0, 255, 255}; };
            static Color_t getGray() { return {128, 128, 128}; };
            static Color_t getOrange() { return {255, 165, 0}; };
            static Color_t getBrown() { return {165, 42, 42}; };

            static Color_t getLightBlue() { return {173, 216, 230}; };
            static Color_t getLightGreen() { return {144, 238, 144}; };
            static Color_t getLightPink() { return {255, 182, 193}; };
            static Color_t getLightYellow() { return {255, 255, 224}; };
            static Color_t getLightGray() { return {211, 211, 211}; };

            static Color_t getDarkGray() { return {169, 169, 169}; };
            static Color_t getDarkRed() { return {139, 0, 0}; };
            static Color_t getDarkGreen() { return {0, 100, 0}; };
            static Color_t getDarkBlue() { return {0, 0, 139}; };
            static Color_t getDarkYellow() { return {139, 139, 0}; };

    }; // class Color

}; // namespace RayTracer

#endif // RAYTRACER_COLOR_HPP

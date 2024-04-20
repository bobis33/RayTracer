/*
** EPITECH PROJECT, 2024
** lib
** File description:
** Color.hpp
*/

#ifndef LIB_COLOR_HPP
#define LIB_COLOR_HPP

#include <cstdint>

using Color_t = struct Color_s {
    uint8_t r{0};
    uint8_t g{0};
    uint8_t b{0};
};

class Color {

    public:
        static Color_t getRed();
        static Color_t getGreen();
        static Color_t getBlue();
        static Color_t getWhite();
        static Color_t getBlack();
        static Color_t getYellow();
        static Color_t getMagenta();
        static Color_t getCyan();
        static Color_t getGray();
        static Color_t getOrange();
        static Color_t getBrown();

        static Color_t getLightBlue();
        static Color_t getLightGreen();
        static Color_t getLightPink();
        static Color_t getLightYellow();
        static Color_t getLightGray();

        static Color_t getDarkGray();
        static Color_t getDarkRed();
        static Color_t getDarkGreen();
        static Color_t getDarkBlue();
        static Color_t getDarkYellow();

}; // class Color

#endif // LIB_COLOR_HPP

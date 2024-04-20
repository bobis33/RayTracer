/*
** EPITECH PROJECT, 2024
** lib
** File description:
** color.cpp
*/

#include "Color/Color.hpp"

Color_t Color::getBlack()
{
    return Color_t{0, 0, 0};
}

Color_t Color::getWhite()
{
    return Color_t{255, 255, 255};
}

Color_t Color::getRed()
{
    return Color_t{255, 0, 0};
}

Color_t Color::getGreen()
{
    return Color_t{0, 255, 0};
}

Color_t Color::getBlue()
{
    return Color_t{0, 0, 255};
}

Color_t Color::getYellow()
{
    return Color_t{255, 255, 0};
}

Color_t Color::getMagenta()
{
    return Color_t{255, 0, 255};
}

Color_t Color::getCyan()
{
    return Color_t{0, 255, 255};
}

Color_t Color::getGray()
{
    return Color_t{128, 128, 128};
}

Color_t Color::getOrange()
{
    return Color_t{255, 165, 0};
}

Color_t Color::getBrown()
{
    return Color_t{165, 42, 42};
}

Color_t Color::getLightBlue()
{
    return Color_t{173, 216, 230};
}

Color_t Color::getLightGreen()
{
    return Color_t{144, 238, 144};
}

Color_t Color::getLightPink()
{
    return Color_t{255, 182, 193};
}

Color_t Color::getLightYellow()
{
    return Color_t{255, 255, 224};
}

Color_t Color::getLightGray()
{
    return Color_t{211, 211, 211};
}

Color_t Color::getDarkGray()
{
    return Color_t{169, 169, 169};
}

Color_t Color::getDarkRed()
{
    return Color_t{139, 0, 0};
}

Color_t Color::getDarkGreen()
{
    return Color_t{0, 100, 0};
}

Color_t Color::getDarkBlue()
{
    return Color_t{0, 0, 139};
}

Color_t Color::getDarkYellow()
{
    return Color_t{139, 139, 0};
}

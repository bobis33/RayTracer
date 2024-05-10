/*
** EPITECH PROJECT, 2024
** raytracer | Parser
** File description:
** utils.cpp
*/

#include <functional>

#include "RayTracer/Parser.hpp"

template<typename T, typename ConversionFunc>
T rtr::Parser::getVector(const libconfig::Setting &setting, ConversionFunc convert)
{
    static_assert(std::is_same_v<T, Vector> || std::is_same_v<T, Color>,
            "T must be either Vector or Color.");

    if (setting.getLength() != 3 || setting.getType() != libconfig::Setting::TypeArray) {
        throw ParserException{"Invalid setting type, expected array of 3 elements (position or color)."};
    }
    return T{convert(setting[0]), convert(setting[1]), convert(setting[2])};
}
template rtr::Vector rtr::Parser::getVector<rtr::Vector, double (*)(libconfig::Setting const&)>(libconfig::Setting const&, double (*)(libconfig::Setting const&));
template rtr::Color rtr::Parser::getVector<rtr::Color, unsigned char (*)(libconfig::Setting const&)>(libconfig::Setting const&, unsigned char(*)(libconfig::Setting const&));

template<typename T>
T rtr::Parser::convertInt(const libconfig::Setting &setting)
{
    if (setting.getType() == libconfig::Setting::Type::TypeInt) {
        int value = setting;
        return static_cast<T>(value);
    }
    throw ParserException{"Invalid setting type, expected an integer."};
}
template double rtr::Parser::convertInt<double>(const libconfig::Setting &setting);
template unsigned short rtr::Parser::convertInt<unsigned short>(const libconfig::Setting &setting);
template unsigned char rtr::Parser::convertInt<unsigned char>(const libconfig::Setting &setting);

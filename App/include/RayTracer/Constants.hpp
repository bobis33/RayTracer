/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Constants.hpp
*/

#ifndef RAYTRACER_CONSTANTS_HPP
#define RAYTRACER_CONSTANTS_HPP

#include <cstdint>

static constexpr int EPITECH_ERROR = 84;
static constexpr int SUCCESS = 0;
static constexpr int ERROR = 1;

static constexpr int DEFAULT_WIDTH = 1920;
static constexpr int DEFAULT_HEIGHT = 1080;

namespace RayTracer {

    enum class RendererType {
        PPM,
        SFML,
        NONE
    };

    enum class ShapeType {
        SPHERE,
        PLANE,
        CYLINDER,
        CONE,
        NONE
    };

    enum class LightType {
        AMBIENT,
        DIRECTIONAL,
        NONE
    };

    enum class MaterialType {
        COLOR,
        NONE
    };

    using Color_t = struct Color_s {
        uint8_t r{0};
        uint8_t g{0};
        uint8_t b{0};
    };

    static constexpr Color_t RED = {255, 0, 0};
    static constexpr Color_t GREEN = {0, 255, 0};
    static constexpr Color_t BLUE = {0, 0, 255};
    static constexpr Color_t WHITE = {255, 255, 255};
    static constexpr Color_t BLACK = {0, 0, 0};

}

#endif //RAYTRACER_CONSTANTS_HPP

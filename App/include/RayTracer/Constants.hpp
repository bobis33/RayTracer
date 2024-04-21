/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Constants.hpp
*/

#ifndef RAYTRACER_CONSTANTS_HPP
#define RAYTRACER_CONSTANTS_HPP

static constexpr int EPITECH_ERROR = 84;
static constexpr int SUCCESS = 0;
static constexpr int ERROR = 1;

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

}

#endif //RAYTRACER_CONSTANTS_HPP

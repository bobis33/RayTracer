/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Constants.hpp
*/

/// @file Constants.hpp
#ifndef RAYTRACER_CONSTANTS_HPP
#define RAYTRACER_CONSTANTS_HPP

static constexpr int EPITECH_ERROR = 84;
static constexpr int SUCCESS = 0;
static constexpr int ERROR = 1;

static constexpr double EPSILON = 1e-6;

static constexpr const char * AMBIENT_LIGHT = "ambient";
static constexpr const char * DIRECTIONAL_LIGHT = "directional";
static constexpr const char * POINT_LIGHT = "point";

static constexpr const char * COMPOSITE_MATERIAL = "materialComposite";
static constexpr const char * TRANSPARENT_MATERIAL = "transparent";
static constexpr const char * REFLECTIVE_MATERIAL = "reflective";

static constexpr const char * PPM_RENDERER = "ppm";
static constexpr const char * SFML_RENDERER = "sfml";

static constexpr const char * SPHERE_SHAPE = "sphere";
static constexpr const char * PLANE_SHAPE = "plane";
static constexpr const char * CYLINDER_SHAPE = "cylinder";
static constexpr const char * CONE_SHAPE = "cone";

namespace rtr {

    /// @enum RendererType
    enum class RendererType {
        PPM,
        SFML,
        NONE
    };

    /// @enum ShapeType
    enum class ShapeType {
        SPHERE,
        PLANE,
        CYLINDER,
        CONE,
        NONE
    };

    /// @enum LightType
    enum class LightType {
        AMBIENT,
        DIRECTIONAL,
        POINT,
        NONE
    };

    /// @enum MaterialType
    enum class MaterialType {
        TRANSPARENT,
        REFLECTIVE,
        NONE
    };

}

#endif //RAYTRACER_CONSTANTS_HPP

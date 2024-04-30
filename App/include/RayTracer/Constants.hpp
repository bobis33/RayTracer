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

static constexpr const char * AMBIENT_LIGHT = "ambientLight";
static constexpr const char * DIRECTIONAL_LIGHT = "directionalLight";
static constexpr const char * POINT_LIGHT = "pointLight";

static constexpr const char * COLOR_MATERIAL = "flatColor";

static constexpr const char * PPM_RENDERER = "ppmRenderer";
static constexpr const char * SFML_RENDERER = "sfmlRenderer";

static constexpr const char * SPHERE_SHAPE = "sphereShape";
static constexpr const char * PLANE_SHAPE = "planeShape";
static constexpr const char * CYLINDER_SHAPE = "cylinderShape";
static constexpr const char * CONE_SHAPE = "coneShape";

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
        POINT,
        NONE
    };

    enum class MaterialType {
        COLOR,
        NONE
    };

}

#endif //RAYTRACER_CONSTANTS_HPP

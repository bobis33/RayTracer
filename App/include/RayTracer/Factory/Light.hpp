/*
** EPITECH PROJECT, 2024
** Raytracer | Factory
** File description:
** Light.hpp
*/

/// @file Light.hpp
#ifndef RAYTRACER_LIGHT_FACTORY_HPP
#define RAYTRACER_LIGHT_FACTORY_HPP

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace rtr {

    /// @class LightFactory
    /// @brief A factory class for the lights.
    class LightFactory {

        public:
            /// @brief Creates a light based on the color and intensity (specific to the ambient light).
            /// @param color The color of the light.
            /// @param intensity The intensity of the light.
            /// @return A unique pointer to the light.
            static std::unique_ptr<ALight> createLight(const Color &color,
                                                       const float &intensity);

            /// @brief Creates a light based on the type, color, intensity and a vector (used for directional and point lights).
            /// @param type The type of the light (defined in the LightType enum class).
            /// @param color The color of the light.
            /// @param intensity The intensity of the light.
            /// @param vector A vector to get the position of the light.
            /// @return A unique pointer to the light.
            static std::unique_ptr<ALight> createLight(const LightType &type,
                                                       const Color &color,
                                                       const float &intensity,
                                                       const Vector &vector);

    }; // class LightFactory

} // namespace RayTracer

#endif //RAYTRACER_LIGHT_FACTORY_HPP

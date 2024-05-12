/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILight.cpp
*/

/// @file ILight.hpp
#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP

#include <vector>

#include "RayTracer/Abstraction/IPlugin.hpp"
#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Constants.hpp"
#include "RayTracer/Utils/Vector.hpp"
#include "RayTracer/Utils/Color.hpp"

namespace rtr {

    /// @class ILight
    /// @brief An interface for lights.
    class ILight : public IPlugin {

        public:

            /// @brief Sets the type of the light (directional, ambient or point).
            /// @param type The type of the light (defined in the enum class LighType).
            virtual void setType(const LightType &type) = 0;

            /// @brief Sets the intensity of the light, based on the configuration file.
            virtual void setIntensity(const float &intensity) = 0;

            /// @brief Creates light effects based on the light type.
            /// @param normal The normal of the shape.
            /// @param col The current color of the shape.
            /// @return The new color of the shape with the light effects.
            virtual Color LightColor(const Vector &normal, const Color &col) = 0;

            /// @brief Gets the type of the light based on the configuration file.
            [[nodiscard]] virtual const LightType& getType() const = 0;

            /// @brief Gets the position of the light based on the configuration file.
            [[nodiscard]] virtual Vector& getPosition() = 0;

            /// @brief Gets the direction of the light based on the configuration file.
            [[nodiscard]] virtual Vector& getDirection() = 0;

            /// @brief Gets the color of the light based on the configuration file.
            [[nodiscard]] virtual Color& getColor() = 0;

            /// @brief Gets the intensity of the light based on the configuration file.
            [[nodiscard]] virtual float& getIntensity() = 0;

    }; // class ILight

} // namespace RayTracer

#endif //RAYTRACER_ILIGHT_HPP

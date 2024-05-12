/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IMaterial
*/

/// @file IMaterial.hpp
#ifndef RAYTRACER_IMATERIAL_HPP
#define RAYTRACER_IMATERIAL_HPP

#include "RayTracer/Abstraction/IPlugin.hpp"
#include "RayTracer/Utils/Color.hpp"
#include "RayTracer/Constants.hpp"

namespace rtr{

    /// @class IMaterial
    /// @brief An interface for materials.
    class IMaterial : public IPlugin {

        public:

            /// @brief Applies the material to the shape (transparency and reflectiveness).
            virtual void applyMaterial(Color* color) = 0;

            /// @brief Sets the type of the material.
            virtual void setType(const MaterialType &type) = 0;

            /// @brief Sets the color of the material.
            /// @param reflectivity The reflectiveness of the material, based on the configuration file.
            virtual void setReflectivity(const float &reflectivity) = 0;

            /// @brief Sets the transparency of the material.
            /// @param transparency The transparency of the material, based on the configuration file.
            virtual void setTransparency(const float &transparency) = 0;

            /// @brief Gets the type of the material based on the configuration file.
            [[nodiscard]] virtual const MaterialType& getType() const = 0;

            /// @brief Gets the color of the material based on the configuration file.
            [[nodiscard]] virtual Color& getColor() = 0;

            /// @brief Gets the reflectiveness of the material based on the configuration file.
            [[nodiscard]] virtual const float& getReflectivity() const = 0;

            /// @brief Gets the transparency of the material based on the configuration file.
            [[nodiscard]] virtual const float& getTransparency() const = 0;

    }; // class IMaterial

}; // namespace RayTracer

#endif //RAYTRACER_IMATERIAL_HPP

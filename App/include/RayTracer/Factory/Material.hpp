/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** Material.hpp
*/

/// @file Material.hpp
#ifndef RAYTRACER_MATERIAL_FACTORY_HPP
#define RAYTRACER_MATERIAL_FACTORY_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace rtr {

    /// @class MaterialFactory
    /// @brief A factory class for the materials of the shapes.
    class MaterialFactory {

        public:

            /// @brief Creates a material based on the type and the color.
            /// @param type The type of the material (defined in the MaterialType enum class).
            /// @param floatValue The value of the transparency and reflectiveness to set.
            /// @return A unique pointer to the material.
            static std::unique_ptr<AMaterial> createMaterial(const MaterialType &type,
                                                             const float &floatValue);

    }; // class MaterialFactory

}; // namespace RayTracer

#endif //RAYTRACER_MATERIAL_FACTORY_HPP

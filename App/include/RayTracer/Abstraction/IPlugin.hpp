/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IPlugin
*/

/// @file IPlugin.hpp
#ifndef RAYTRACER_IPLUGIN_HPP
#define RAYTRACER_IPLUGIN_HPP

#include <string>

namespace rtr {

    /// @class IPlugin
    /// @brief An interface for plugins.
    class IPlugin {

        public:

            virtual ~IPlugin() = default;

            /// @brief Gets the name of the plugin.
            /// @return A string of the plugin's name, defined as const expressions.
            [[nodiscard]] virtual std::string getPluginName() const = 0;

    }; // class IPlugin

} // namespace RayTracer

#endif //RAYTRACER_IPLUGIN_HPP

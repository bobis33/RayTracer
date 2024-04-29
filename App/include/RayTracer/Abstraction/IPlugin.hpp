/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IPlugin
*/

#ifndef RAYTRACER_IPLUGIN_HPP
#define RAYTRACER_IPLUGIN_HPP

#include <string>

namespace RayTracer {

    class IPlugin {

        public:
            virtual ~IPlugin() = default;

            [[nodiscard]] virtual std::string getPluginName() const = 0;

    }; // class IPlugin

} // namespace RayTracer

#endif //RAYTRACER_IPLUGIN_HPP

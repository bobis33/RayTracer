/*
** EPITECH PROJECT, 2024
** Raytracer | rendererFactory
** File description:
** LightsFactory.hpp
*/

#ifndef RAYTRACER_LIGHTS_FACTORY_HPP
#define RAYTRACER_LIGHTS_FACTORY_HPP

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/PluginLoader.hpp"

namespace RayTracer {

    class RendererFactory {
        public:
            static std::unique_ptr<ALights> createLights(const LightType &type,
                                                         const std::tuple<uint16_t, uint16_t, uint16_t> &position)
            {
                std::unique_ptr<ALights> lights;
                switch (type) {
                    case LightType::AMBIENT:
                        lights = PluginLoader::loadPlugin<ALights>("./plugins/raytracer_ambient_light.so");
                        break;
                    case LightType::DIRECTIONAL:
                        lights = PluginLoader::loadPlugin<ALights>("./plugins/raytracer_directional_light.so");
                        break;
                    default:
                        throw RunTimeException("Lights type not found");
                }
                lights->setType(type);
                lights->setPosition(position);
                return lights;
            };

    }; // class LightsFactory

} // namespace RayTracer

#endif //RAYTRACER_LIGHTS_FACTORY_HPP

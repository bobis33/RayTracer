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
            static std::unique_ptr<ALight> createLights(const LightType &type,
                                                         const std::tuple<uint16_t, uint16_t, uint16_t> &position)
            {
                std::unique_ptr<ALight> lights;
                switch (type) {
                    case LightType::AMBIENT:
                        lights = PluginLoader::loadPlugin<ALight>("./plugins/light_ambient.so");
                        break;
                    case LightType::DIRECTIONAL:
                        lights = PluginLoader::loadPlugin<ALight>("./plugins/light_directional.so");
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

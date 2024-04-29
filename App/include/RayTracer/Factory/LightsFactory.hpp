/*
** EPITECH PROJECT, 2024
** Raytracer | lightsFactory
** File description:
** LightsFactory.hpp
*/

#ifndef RAYTRACER_LIGHTS_FACTORY_HPP
#define RAYTRACER_LIGHTS_FACTORY_HPP

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Loader/PluginLoader.hpp"

namespace RayTracer {

    class RendererFactory {
        public:
            static std::unique_ptr<ALight> createLights(const LightType &type,
                                                        const vector_t &position,
                                                        const color_t &color)
            {
                std::unique_ptr<ALight> lights;
                switch (type) {
                    case LightType::AMBIENT:
                        lights = PluginLoader::getInstance().getPlugin<ALight>("AmbientLight");
                        break;
                    case LightType::DIRECTIONAL:
                        lights = PluginLoader::getInstance().getPlugin<ALight>("DirectionalLight");
                        break;
                    default:
                        throw RunTimeException("Lights type not found");
                }
                lights->setType(type);
                lights->getPosition().setPosition(position);
                lights->getColor().setColor(color);
                return lights;
            };

    }; // class LightsFactory

} // namespace RayTracer

#endif //RAYTRACER_LIGHTS_FACTORY_HPP

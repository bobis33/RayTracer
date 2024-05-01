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
                                                        const Vector &position,
                                                        const Color &color)
            {
                std::unique_ptr<ALight> lights;
                switch (type) {
                    case LightType::AMBIENT:
                        lights = PluginLoader::getInstance().getPlugin<ALight>(AMBIENT_LIGHT);
                        break;
                    case LightType::DIRECTIONAL:
                        lights = PluginLoader::getInstance().getPlugin<ALight>(DIRECTIONAL_LIGHT);
                        break;
                    case LightType::POINT:
                        lights = PluginLoader::getInstance().getPlugin<ALight>(POINT_LIGHT);
                        break;
                    default:
                        throw RunTimeException("Lights type not found");
                }
                lights->setType(type);
                lights->getPosition().setPosition(position.getValue());
                lights->getColor().setColor(color.getValue());
                return lights;
            };

    }; // class LightsFactory

} // namespace RayTracer

#endif //RAYTRACER_LIGHTS_FACTORY_HPP

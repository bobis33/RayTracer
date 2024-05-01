/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** lightsFactory.cpp
*/

#include "RayTracer/Factory/LightsFactory.hpp"

std::unique_ptr<RayTracer::ALight> RayTracer::LightsFactory::createLights(const LightType &type,
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


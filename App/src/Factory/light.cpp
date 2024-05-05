/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** light.cpp
*/

#include "RayTracer/Factory/Light.hpp"

std::unique_ptr<RayTracer::ALight> RayTracer::LightFactory::createLight(const LightType &type,
                                                                        const Vector &position,
                                                                        const Color &color,
                                                                        const float &intensity)
{
    std::unique_ptr<ALight> light;
    switch (type) {
        case LightType::AMBIENT:
            light = PluginLoader::getInstance().getPlugin<ALight>(AMBIENT_LIGHT);
            break;
        case LightType::POINT:
            light = PluginLoader::getInstance().getPlugin<ALight>(POINT_LIGHT);
            break;
        default:
            throw RunTimeException("Lights type not found");
    }
    light->setType(type);
    light->getPosition().setVector(position.getValue());
    light->getColor().setColor(color.getValue());
    light->setIntensity(intensity);
    return light;
};

std::unique_ptr<RayTracer::ALight> RayTracer::LightFactory::createLight(const Vector &position,
                                                                        const Color &color,
                                                                        const float &intensity,
                                                                        const Vector &direction)
{
    std::unique_ptr<ALight> light(PluginLoader::getInstance().getPlugin<ALight>(DIRECTIONAL_LIGHT));

    light->setType(LightType::DIRECTIONAL);
    light->getPosition().setVector(position.getValue());
    light->getColor().setColor(color.getValue());
    light->setIntensity(intensity);
    light->getDirection().setVector(direction.getValue());
    return light;
};

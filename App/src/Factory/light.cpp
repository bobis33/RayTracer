/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** light.cpp
*/

#include "RayTracer/Factory/Light.hpp"

std::unique_ptr<rtr::ALight> rtr::LightFactory::createLight(const Color &color,
                                                            const float &intensity)
{
    std::unique_ptr<ALight> light(PluginLoader::getInstance().getPlugin<ALight>(AMBIENT_LIGHT));
    light->setType(LightType::AMBIENT);
    light->getColor().setColor(color.getValue());
    light->setIntensity(intensity);
    return light;
};

std::unique_ptr<rtr::ALight> rtr::LightFactory::createLight(const LightType &type,
                                                            const Color &color,
                                                            const float &intensity,
                                                            const Vector &vector)
{
    std::unique_ptr<ALight> light;
    switch (type) {
        case LightType::POINT:
            light = PluginLoader::getInstance().getPlugin<ALight>(POINT_LIGHT);
            light->getPosition().setVector(vector.getValue());
            break;
        case LightType::DIRECTIONAL:
            light = PluginLoader::getInstance().getPlugin<ALight>(DIRECTIONAL_LIGHT);
            light->getDirection().setVector(vector.getValue());
            break;
        default:
            throw RunTimeException("Invalid light type");
    }
    light->setType(type);
    light->getColor().setColor(color.getValue());
    light->setIntensity(intensity);
    return light;
};


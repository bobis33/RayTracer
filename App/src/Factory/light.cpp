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

std::unique_ptr<rtr::ALight> rtr::LightFactory::createLight(const Color &color,
                                                            const float &intensity,
                                                            const Vector &direction,
                                                            const Vector &position)
{
    std::unique_ptr<ALight> light(PluginLoader::getInstance().getPlugin<ALight>(DIRECTIONAL_LIGHT));
    light->setType(LightType::DIRECTIONAL);
    light->getColor().setColor(color.getValue());
    light->setIntensity(intensity);
    light->getDirection().setVector(direction.getValue());
    light->getPosition().setVector(position.getValue());
    return light;
};

std::unique_ptr<rtr::ALight> rtr::LightFactory::createLight(const Color &color,
                                                            const float &intensity,
                                                            const Vector &position)
{
    std::unique_ptr<ALight> light(PluginLoader::getInstance().getPlugin<ALight>(POINT_LIGHT));
    light->setType(LightType::POINT);
    light->getColor().setColor(color.getValue());
    light->setIntensity(intensity);
    light->getPosition().setVector(position.getValue());
    return light;
};
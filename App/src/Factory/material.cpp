/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** material.cpp
*/

#include "RayTracer/Factory/Material.hpp"

std::unique_ptr<RayTracer::AMaterial> RayTracer::MaterialFactory::createMaterial(const MaterialType &type,
                                                                                 const float &floatValue)
{
    std::unique_ptr<AMaterial> material;
    switch (type) {
        case MaterialType::REFLECTIVE:
            material = PluginLoader::getInstance().getPlugin<AMaterial>(REFLECTIVE_MATERIAL);
            material->setReflectivity(floatValue);
            break;
        case MaterialType::TRANSPARENT:
            material = PluginLoader::getInstance().getPlugin<AMaterial>(TRANSPARENT_MATERIAL);
            material->setTransparency(floatValue);
            break;
        default:
            throw RunTimeException("Materials type not found");
    }
    material->setType(type);
    return material;
};
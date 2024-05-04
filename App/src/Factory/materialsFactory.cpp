/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** materialsFactory.cpp
*/

#include "RayTracer/Factory/MaterialsFactory.hpp"

std::unique_ptr<RayTracer::AMaterial> RayTracer::MaterialsFactory::createMaterials(const MaterialType &type,
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
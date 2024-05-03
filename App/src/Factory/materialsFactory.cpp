/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** materialsFactory.cpp
*/

#include "RayTracer/Factory/MaterialsFactory.hpp"

std::unique_ptr<RayTracer::AMaterial> RayTracer::MaterialsFactory::createMaterials(const MaterialType &type,
                                                                                   const Color &color)
{
    std::unique_ptr<AMaterial> material;
    switch (type) {
        case MaterialType::COLOR:
            material = PluginLoader::getInstance().getPlugin<AMaterial>(COLOR_MATERIAL);
            break;
        default:
            throw RunTimeException("Materials type not found");
    }
    material->setType(type);
    material->getColor().setColor(color.getValue());
    return material;
};
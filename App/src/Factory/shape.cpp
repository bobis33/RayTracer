/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** shape.cpp
*/

#include "RayTracer/Factory/Shape.hpp"

std::unique_ptr<RayTracer::AShape> RayTracer::ShapeFactory::createShape(const ShapeType &type,
                                                                        const Vector &position)
{
    std::unique_ptr<AShape> shape;

    switch (type) {
        case ShapeType::PLANE:
            shape = PluginLoader::getInstance().getPlugin<AShape>(PLANE_SHAPE);
            break;
        default:
            throw RunTimeException("Invalid shape type");
    }

    shape->setType(type);
    shape->getPosition().setPosition(position.getValue());
    return shape;
}

std::unique_ptr<RayTracer::AShape> RayTracer::ShapeFactory::createShape(const ShapeType &type,
                                                                        const Vector &position,
                                                                        int16_t &radius)
{
    std::unique_ptr<AShape> shape;

    switch (type) {
        case ShapeType::SPHERE:
            shape = PluginLoader::getInstance().getPlugin<AShape>(SPHERE_SHAPE);
            break;
        case ShapeType::CYLINDER:
            shape = PluginLoader::getInstance().getPlugin<AShape>(CYLINDER_SHAPE);
            break;
        case ShapeType::CONE:
            shape = PluginLoader::getInstance().getPlugin<AShape>(CONE_SHAPE);
            break;
        default:
            throw RunTimeException("Invalid shape type");
    }

    shape->setType(type);
    shape->getPosition().setPosition(position.getValue());
    shape->setRadius(radius);
    return shape;
}
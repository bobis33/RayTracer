/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** shape.cpp
*/

#include "RayTracer/Factory/Shape.hpp"

std::unique_ptr<RayTracer::AShape> RayTracer::ShapeFactory::createShape(const Vector &position)
{
    std::unique_ptr<AShape> shape(PluginLoader::getInstance().getPlugin<AShape>(PLANE_SHAPE));

    shape->setType(ShapeType::PLANE);
    shape->getPosition().setVector(position.getValue());
    return shape;
}

std::unique_ptr<RayTracer::AShape> RayTracer::ShapeFactory::createShape(const Vector &position,
                                                                        const double &radius)
{
    std::unique_ptr<AShape> shape(PluginLoader::getInstance().getPlugin<AShape>(SPHERE_SHAPE));

    shape->setType(ShapeType::SPHERE);
    shape->getPosition().setVector(position.getValue());
    shape->setRadius(radius);
    return shape;
}

std::unique_ptr<RayTracer::AShape> RayTracer::ShapeFactory::createShape(const ShapeType &type,
                                                                        const Vector &position,
                                                                        const Vector &rotation,
                                                                        const double &radius)
{
    std::unique_ptr<AShape> shape;

    switch (type) {
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
    shape->getPosition().setVector(position.getValue());
    shape->getRotation().setVector(rotation.getValue());
    shape->setRadius(radius);
    return shape;
}
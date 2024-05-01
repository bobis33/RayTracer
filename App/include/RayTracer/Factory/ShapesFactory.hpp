/*
** EPITECH PROJECT, 2024
** Raytracer | shapesFactory
** File description:
** ShapesFactory.hpp
*/

#ifndef RAYTRACER_SHAPES_FACTORY_HPP
#define RAYTRACER_SHAPES_FACTORY_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Loader/PluginLoader.hpp"

namespace RayTracer {

    class ShapesFactory {
        public:
            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const vector_t &position)
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
                shape->getPosition().setPosition(position);
                return shape;
            };

            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const vector_t &position,
                                                       int16_t radius)
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
                shape->getPosition().setPosition(position);
                shape->setRadius(radius);
                return shape;
            };

    }; // class ShapesFactory

} // namespace RayTracer

#endif //RAYTRACER_SHAPES_FACTORY_HPP

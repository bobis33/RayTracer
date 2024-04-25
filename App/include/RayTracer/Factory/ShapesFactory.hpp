/*
** EPITECH PROJECT, 2024
** Raytracer | rendererFactory
** File description:
** ShapesFactory.hpp
*/

#ifndef RAYTRACER_SHAPES_FACTORY_HPP
#define RAYTRACER_SHAPES_FACTORY_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/PluginLoader.hpp"

namespace RayTracer {

    class ShapesFactory {
        public:
            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const Position_t &position)
            {
                std::unique_ptr<AShape> shape;

                switch (type) {
                case ShapeType::PLANE:
                    shape = PluginLoader::loadPlugin<AShape>("./plugins/shape_cone.so");
                    break;
                default:
                    throw RunTimeException("Invalid shape type");
                }

                shape->setType(type);
                shape->getPosition().setPosition(position);
                return shape;
            };

            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const Position_t &position,
                                                       float radius)
            {
                std::unique_ptr<AShape> shape;

                switch (type) {
                    case ShapeType::SPHERE:
                        shape = PluginLoader::loadPlugin<AShape>("./plugins/shape_sphere.so");
                        break;
                    case ShapeType::CYLINDER:
                        shape = PluginLoader::loadPlugin<AShape>("./plugins/shape_cylinder.so");
                        break;
                    case ShapeType::CONE:
                        shape = PluginLoader::loadPlugin<AShape>("./plugins/shape_sphere.so");
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

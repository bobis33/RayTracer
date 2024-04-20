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
            static std::unique_ptr<AShapes> createShape(const ShapeType &type,
                                                        const std::tuple<uint16_t, uint16_t, uint16_t> &position,
                                                        const std::tuple<uint8_t, uint8_t, uint8_t> &color)
            {
                std::unique_ptr<AShapes> shape;

                switch (type) {
                case ShapeType::PLANE:
                    shape = PluginLoader::loadPlugin<AShapes>("./plugins/raytracer_cone_shape.so");
                    break;
                default:
                    throw RunTimeException("Invalid shape type");
                }

                shape->setType(type);
                shape->setPosition(position);
                shape->setColor(color);
                return shape;
            };

            static std::unique_ptr<AShapes> createShape(const ShapeType &type,
                                                        const std::tuple<uint16_t, uint16_t, uint16_t> &position,
                                                        const std::tuple<uint8_t, uint8_t, uint8_t> &color,
                                                        float radius)
            {
                std::unique_ptr<AShapes> shape;

                switch (type) {
                    case ShapeType::SPHERE:
                        shape = PluginLoader::loadPlugin<AShapes>("./plugins/raytracer_sphere_shape.so");
                        break;
                    case ShapeType::CYLINDER:
                        shape = PluginLoader::loadPlugin<AShapes>("./plugins/raytracer_cylinder_shape.so");
                        break;
                    case ShapeType::CONE:
                        shape = PluginLoader::loadPlugin<AShapes>("./plugins/raytracer_sphere_shape.so");
                        break;
                    default:
                        throw RunTimeException("Invalid shape type");
                }

                shape->setType(type);
                shape->setPosition(position);
                shape->setColor(color);
                shape->setRadius(radius);
                return shape;
            };

    }; // class ShapesFactory

} // namespace RayTracer

#endif //RAYTRACER_SHAPES_FACTORY_HPP

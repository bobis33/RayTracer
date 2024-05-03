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
                                                       const Vector &position);

            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const Vector &position,
                                                       int16_t &radius);

    }; // class ShapesFactory

} // namespace RayTracer

#endif //RAYTRACER_SHAPES_FACTORY_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Factory
** File description:
** ShapeFactory.hpp
*/

#ifndef RAYTRACER_SHAPE_FACTORY_HPP
#define RAYTRACER_SHAPE_FACTORY_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace RayTracer {

    class ShapeFactory {

        public:

            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const Vector &position);

            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const Vector &position,
                                                       int16_t &radius);

    }; // class ShapeFactory

} // namespace RayTracer

#endif //RAYTRACER_SHAPE_FACTORY_HPP

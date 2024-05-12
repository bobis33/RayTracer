/*
** EPITECH PROJECT, 2024
** Raytracer | Factory
** File description:
** ShapeFactory.hpp
*/

/// @file Shape.hpp
#ifndef RAYTRACER_SHAPE_FACTORY_HPP
#define RAYTRACER_SHAPE_FACTORY_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace rtr {

    /// @class ShapeFactory
    /// @brief A factory class for the shapes.
    class ShapeFactory {

        public:

            /// @brief Creates a shape based on the position and normal (for the plane).
            /// @param position Used to get the position of the shape.
            /// @param normal Used to get the normal of the shape.
            /// @return A unique pointer to the shape.
            static std::unique_ptr<AShape> createShape(const Vector &position,
                                                       const Vector &normal);

            /// @brief Creates a shape based on the position and radius (for the sphere).
            /// @param position Used to get the position of the shape.
            /// @param radius Used to get the radius of the shape.
            /// @return A unique pointer to the shape.
            static std::unique_ptr<AShape> createShape(const Vector &position,
                                                       const double &radius);

            /// @brief Creates a shape based on the type position, rotation, radius and height.
            /// @param type The type of the shape (defined in the ShapeType enum class).
            /// @param position Used to get the position of the shape.
            /// @param rotation Used to get the rotation of the shape.
            /// @param radius Used to get the radius of the shape.
            /// @param height Used to get the height of the shape.
            /// @return A unique pointer to the shape.
            static std::unique_ptr<AShape> createShape(const ShapeType &type,
                                                       const Vector &position,
                                                       const Vector &rotation,
                                                       const double &radius,
                                                       const double &height);
    }; // class ShapeFactory

} // namespace RayTracer

#endif //RAYTRACER_SHAPE_FACTORY_HPP

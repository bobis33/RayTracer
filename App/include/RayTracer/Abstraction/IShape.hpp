/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape.cpp
*/

/// @file IShape.hpp
#ifndef RAYTRACER_ISHAPE_HPP
#define RAYTRACER_ISHAPE_HPP

#include <memory>

#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/Constants.hpp"
#include "RayTracer/Utils/Vector.hpp"
#include "RayTracer/Utils/RayHit.hpp"

namespace rtr {

    /// @class IShape
    /// @brief An interface used to get the shape's parameters based on the configuration file.
    class IShape : public IPlugin {

        public:

            /// @brief Sets the type of the shape (sphere, plane, cone...).
            /// @param type The type of the shape.
            virtual void setType(const ShapeType& type) = 0;

            /// @brief Sets the material of the shape.
            /// @param material The material of the shape (transparency, reflectivity...).
            virtual void setMaterial(std::unique_ptr<AMaterial> material) = 0;

            /// @brief Sets the radius of the shape.
            /// @param radius The radius of the shape.
            virtual void setRadius(const double& radius) = 0;

            /// @brief Sets the height of the shape.
            /// @param height The height of the shape.
            virtual void setHeight(const double& height) = 0;

            /// @brief Gets the type of the shape.
            /// @return The type of the shape, using the ShapeType enum class.
            [[nodiscard]] virtual const ShapeType& getType() const = 0;

            /// @brief Gets the material of the shape.
            /// @return The material of the shape, using the AMaterial class.
            [[nodiscard]] virtual AMaterial& getMaterial() = 0;

            /// @brief Gets the position of the shape.
            /// @return The position of the shape, using the Vector class.
            [[nodiscard]] virtual Vector& getPosition() = 0;

            /// @brief Gets the normal of the shape.
            /// @return The normal of the shape, using the Vector class.
            [[nodiscard]] virtual Vector& getNormal() = 0;

            /// @brief Gets the rotation of the shape, used to create the shape.
            /// @return The rotation of the shape, using the Vector class.
            [[nodiscard]] virtual Vector& getRotation() = 0;

            /// @brief Gets the radius of the shape.
            /// @return The radius of the shape as a double, used to check the size of the shape.
            [[nodiscard]] virtual const double &getRadius() const = 0;

            /// @brief Gets the height of the shape.
            /// @return The height of the shape as a double.
            [[nodiscard]] virtual const double &getHeight() const = 0;

            /// @brief Checks if the ray hits the shape, used to render the output file.
            /// @param ray A pair of vectors, to get the rays of the "camera".
            /// @param hit The hit of the ray, used to check if the ray hits the shape.
            /// @return A boolean, true if the ray hits the shape, false otherwise.
            [[nodiscard]] virtual bool hits(std::pair<Vector, Vector> ray, RayHit &hit) = 0;

            /// @brief Gets the distance between the shape and a point.
            /// @param point The point to check the distance with.
            /// @return The distance between the shape and the point.
            [[nodiscard]] virtual Vector getDistance(const Vector& point) = 0;

    }; // IShape

} // namespace RayTracer

#endif //RAYTRACER_ISHAPE_HPP

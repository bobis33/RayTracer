/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape.cpp
*/

#ifndef RAYTRACER_ISHAPE_HPP
#define RAYTRACER_ISHAPE_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/Constants.hpp"
#include "RayTracer/Position.hpp"

namespace RayTracer {

    class IShape {

        public:
            virtual ~IShape() = default;

            virtual void setType(const ShapeType& type) = 0;
            virtual void setRadius(float radius) = 0;
            virtual void setMaterial(AMaterial *material) = 0;

            [[nodiscard]] virtual ShapeType getType() const = 0;
            [[nodiscard]] virtual AMaterial getMaterial() const = 0;
            [[nodiscard]] virtual Position getPosition() const = 0;
            [[nodiscard]] virtual float getRadius() const = 0;

    }; // IShape

} // namespace RayTracer

#endif //RAYTRACER_ISHAPE_HPP

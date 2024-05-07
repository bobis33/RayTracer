/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IShape.cpp
*/

#ifndef RAYTRACER_ISHAPE_HPP
#define RAYTRACER_ISHAPE_HPP

#include <memory>

#include "RayTracer/Abstraction/IPlugin.hpp"
#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/Constants.hpp"
#include "RayTracer/Utils/Vector.hpp"

namespace RayTracer {

    class IShape : public IPlugin {

        public:

            virtual void setType(const ShapeType& type) = 0;
            virtual void setRadius(const double& radius) = 0;
            virtual void setMaterial(std::unique_ptr<AMaterial> material) = 0;

            [[nodiscard]] virtual const ShapeType& getType() const = 0;
            [[nodiscard]] virtual AMaterial& getMaterial() = 0;
            [[nodiscard]] virtual Vector& getPosition() = 0;
            [[nodiscard]] virtual Vector& getRotation() = 0;
            [[nodiscard]] virtual double getRadius() const = 0;

            [[nodiscard]] virtual bool hits(std::pair<Vector, Vector> ray) = 0;

    }; // IShape

} // namespace RayTracer

#endif //RAYTRACER_ISHAPE_HPP

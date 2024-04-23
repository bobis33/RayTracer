/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILight.cpp
*/

#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP

#include "RayTracer/Constants.hpp"
#include "RayTracer/Utils/Vector.hpp"
#include "RayTracer/Utils/Color.hpp"

namespace RayTracer {

    class ILight {

        public:
            virtual ~ILight() = default;

            virtual void setType(const LightType &type) = 0;

            [[nodiscard]] virtual LightType getType() const = 0;
            [[nodiscard]] virtual Vector& getPosition() = 0;
            [[nodiscard]] virtual Color& getColor() = 0;

    }; // class ILight

} // namespace RayTracer

#endif //RAYTRACER_ILIGHT_HPP

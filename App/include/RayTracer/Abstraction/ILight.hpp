/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILight.cpp
*/

#ifndef RAYTRACER_ILIGHT_HPP
#define RAYTRACER_ILIGHT_HPP

#include "RayTracer/Abstraction/IPlugin.hpp"
#include "RayTracer/Constants.hpp"
#include "RayTracer/Utils/Vector.hpp"
#include "RayTracer/Utils/Color.hpp"

namespace RayTracer {

    class ILight : public IPlugin {

        public:

            virtual void setType(const LightType &type) = 0;
            virtual void setIntensity(const float &intensity) = 0;

            [[nodiscard]] virtual const LightType& getType() const = 0;
            [[nodiscard]] virtual Vector& getPosition() = 0;
            [[nodiscard]] virtual Vector& getDirection() = 0;
            [[nodiscard]] virtual Color& getColor() = 0;
            [[nodiscard]] virtual float& getIntensity() = 0;

    }; // class ILight

} // namespace RayTracer

#endif //RAYTRACER_ILIGHT_HPP

/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IMaterial
*/

#ifndef RAYTRACER_IMATERIAL_HPP
#define RAYTRACER_IMATERIAL_HPP

#include "RayTracer/Abstraction/IPlugin.hpp"
#include "RayTracer/Utils/Color.hpp"
#include "RayTracer/Constants.hpp"

namespace RayTracer{

    class IMaterial : public IPlugin {

        public:

            virtual void applyMaterial(Color* color) = 0;

            virtual void setType(const MaterialType &type) = 0;
            virtual void setReflectivity(const float &reflectivity) = 0;
            virtual void setTransparency(const float &transparency) = 0;

            [[nodiscard]] virtual const MaterialType& getType() const = 0;
            [[nodiscard]] virtual Color& getColor() = 0;
            [[nodiscard]] virtual const float& getReflectivity() const = 0;
            [[nodiscard]] virtual const float& getTransparency() const = 0;

    }; // class IMaterial

}; // namespace RayTracer

#endif //RAYTRACER_IMATERIAL_HPP

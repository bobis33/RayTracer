/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IMaterials
*/

#ifndef RAYTRACER_IMATERIALS_HPP
#define RAYTRACER_IMATERIALS_HPP

#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class IMaterials {

        public:

            virtual ~IMaterials() = default;

            virtual void setType(const MaterialType &type) = 0;
            virtual void setColor(const Color_t &color) = 0;
            virtual void setReflectivity(const uint8_t &reflectivity) = 0;
            virtual void setTransparency(const uint8_t &transparency) = 0;

            virtual MaterialType getType() const = 0;
            virtual Color_t getColor() const = 0;
            virtual uint8_t getReflectivity() const = 0;
            virtual uint8_t getTransparency() const = 0;

    }; // class IMaterials

}; // namespace RayTracer

#endif //RAYTRACER_IMATERIALS_HPP

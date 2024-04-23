/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** IMaterial
*/

#ifndef RAYTRACER_IMATERIAL_HPP
#define RAYTRACER_IMATERIAL_HPP

#include <string>

#include "RayTracer/Utils/Color.hpp"
#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class IMaterial {

        public:

            virtual ~IMaterial() = default;

            virtual void setType(const MaterialType &type) = 0;
            virtual void setName(const std::string &name) = 0;
            virtual void setReflectivity(const uint8_t &reflectivity) = 0;
            virtual void setTransparency(const uint8_t &transparency) = 0;

            [[nodiscard]] virtual MaterialType getType() const = 0;
            [[nodiscard]] virtual Color& getColor() = 0;
            [[nodiscard]] virtual std::string getName() const = 0;
            [[nodiscard]] virtual float getReflectivity() const = 0;
            [[nodiscard]] virtual float getTransparency() const = 0;

    }; // class IMaterial

}; // namespace RayTracer

#endif //RAYTRACER_IMATERIAL_HPP

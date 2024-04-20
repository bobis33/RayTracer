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

            virtual MaterialType getType() const = 0;

    }; // class IMaterials

}; // namespace RayTracer

#endif //RAYTRACER_IMATERIALS_HPP

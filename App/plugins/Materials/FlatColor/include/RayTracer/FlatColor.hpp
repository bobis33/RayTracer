/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** FlatColor.hpp
*/

#ifndef RAYTRACER_FLAT_COLOR_HPP
#define RAYTRACER_FLAT_COLOR_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"

namespace RayTracer {

    class FlatColor : public AMaterial {

        public:
            ~FlatColor() override = default;

    }; // class FlatColor

} // namespace RayTracer

#endif // RAYTRACER_FLAT_COLOR_HPP

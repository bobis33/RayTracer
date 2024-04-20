/*
** EPITECH PROJECT, 2024
** Raytracer | Lights
** File description:
** Color.hpp
*/

#ifndef RAYTRACER_COLOR_HPP
#define RAYTRACER_COLOR_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"

namespace RayTracer {

    class Color : public AMaterial {

        public:
            ~Color() override = default;

    }; // class Color

} // namespace RayTracer

#endif // RAYTRACER_COLOR_HPP

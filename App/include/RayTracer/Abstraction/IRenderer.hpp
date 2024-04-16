/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IRenderer.cpp
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

#include "RayTracer/Parser.hpp"

namespace RayTracer {

    class IRenderer {

        public:
            virtual ~IRenderer() = default;

            virtual void render(const Scene &scene) = 0;

    }; // IRenderer

} // namespace RayTracer

#endif //RAYTRACER_IRENDERER_HPP

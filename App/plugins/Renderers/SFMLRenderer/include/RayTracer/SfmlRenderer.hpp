/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** SfmlRenderer.hpp
*/

#ifndef RAYTRACER_SFML_RENDERER_HPP
#define RAYTRACER_SFML_RENDERER_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"

namespace RayTracer {

    class SfmlRenderer : public ARenderer {

        public:
            ~SfmlRenderer() override = default;

            void render(const Scene &scene) override;

    }; // class SfmlRenderer

} // namespace RayTracer

#endif // RAYTRACER_SFML_RENDERER_HPP

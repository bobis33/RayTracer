/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** PpmRenderer.hpp
*/

#ifndef RAYTRACER_PPM_RENDERER_HPP
#define RAYTRACER_PPM_RENDERER_HPP

#include "RayTracer/Abstraction/IRenderer.hpp"
#include "RayTracer/Parser.hpp"

namespace RayTracer {

    class PpmRenderer : public IRenderer {

        public:
            ~PpmRenderer() override = default;

            void render(const Scene &scene) override;

    }; // class PpmRenderer

} // namespace RayTracer

#endif // RAYTRACER_PPM_RENDERER_HPP

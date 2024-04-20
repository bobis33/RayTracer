/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** PpmRenderer.hpp
*/

#ifndef RAYTRACER_PPM_RENDERER_HPP
#define RAYTRACER_PPM_RENDERER_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"

namespace RayTracer {

    class PpmRenderer : public ARenderer {

        public:
            ~PpmRenderer() override = default;

            void render() override;

    }; // class PpmRenderer

} // namespace RayTracer

#endif // RAYTRACER_PPM_RENDERER_HPP

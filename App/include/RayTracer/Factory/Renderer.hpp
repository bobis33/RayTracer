/*
** EPITECH PROJECT, 2024
** Raytracer | Factory
** File description:
** Renderer.hpp
*/

#ifndef RAYTRACER_RENDERER_FACTORY_HPP
#define RAYTRACER_RENDERER_FACTORY_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace rtr {

    class RendererFactory {

        public:
            static std::unique_ptr<ARenderer> createRenderer(const RendererType &type,
                                                             const std::string &name,
                                                             const Resolution &resolution,
                                                             const Color &backgroundColor);

    }; // class RendererFactory

} // namespace RayTracer

#endif //RAYTRACER_RENDERER_FACTORY_HPP

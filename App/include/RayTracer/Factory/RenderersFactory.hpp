/*
** EPITECH PROJECT, 2024
** Raytracer | renderersFactory
** File description:
** rendererFactory.hpp
*/

#ifndef RAYTRACER_RENDERERS_FACTORY_HPP
#define RAYTRACER_RENDERERS_FACTORY_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Loader/PluginLoader.hpp"

namespace RayTracer {

    class RenderersFactory {

        public:
            static std::unique_ptr<ARenderer> createRenderer(const RendererType &type,
                                                             const std::string &name,
                                                             const Resolution &resolution);

    }; // class RendererFactory

} // namespace RayTracer

#endif //RAYTRACER_RENDERERS_FACTORY_HPP

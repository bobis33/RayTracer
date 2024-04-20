/*
** EPITECH PROJECT, 2024
** Raytracer | rendererFactory
** File description:
** rendererFactory.hpp
*/

#ifndef RAYTRACER_RENDERER_FACTORY_HPP
#define RAYTRACER_RENDERER_FACTORY_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/PluginLoader.hpp"

namespace RayTracer {

    class RendererFactory {
        public:
            static std::unique_ptr<ARenderer> createRenderer(const RendererType &type)
            {
                std::unique_ptr<ARenderer> renderer;
                switch (type) {
                    case RendererType::PPM:
                        renderer = PluginLoader::loadPlugin<ARenderer>("./plugins/raytracer_ppm_renderer.so");
                        break;
                    case RendererType::SFML:
                        renderer = PluginLoader::loadPlugin<ARenderer>("./plugins/raytracer_sfml_renderer.so");
                        break;
                    default:
                        throw RunTimeException("Renderer type not found");
                }
                return renderer;
            };

    }; // class RendererFactory

} // namespace RayTracer

#endif //RAYTRACER_RENDERER_FACTORY_HPP

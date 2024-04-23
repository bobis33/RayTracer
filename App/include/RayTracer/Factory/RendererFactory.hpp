/*
** EPITECH PROJECT, 2024
** Raytracer | rendererFactory
** File description:
** rendererFactory.hpp
*/

#ifndef RAYTRACER_RENDERER_FACTORY_HPP
#define RAYTRACER_RENDERER_FACTORY_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Loader/PluginLoader.hpp"

namespace RayTracer {

    class RendererFactory {
        public:
            static std::unique_ptr<ARenderer> createRenderer(const RendererType &type,
                                                             const std::string &name,
                                                             const resolution_t &resolution)
            {
                std::unique_ptr<ARenderer> renderer;
                switch (type) {
                    case RendererType::PPM:
                        renderer = PluginLoader::loadPlugin<ARenderer>("./plugins/renderer_ppm.so");
                        break;
                    case RendererType::SFML:
                        renderer = PluginLoader::loadPlugin<ARenderer>("./plugins/renderer_sfml.so");
                        break;
                    default:
                        throw RunTimeException("Renderer type not found");
                }
                renderer->setType(type);
                renderer->getResolution().setResolution(resolution);
                renderer->setName(name);
                return renderer;
            };

    }; // class RendererFactory

} // namespace RayTracer

#endif //RAYTRACER_RENDERER_FACTORY_HPP

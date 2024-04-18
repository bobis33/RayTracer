/*
** EPITECH PROJECT, 2024
** Raytracer | rendererFactory
** File description:
** rendererFactory.hpp
*/

#ifndef RAYTRACER_RENDERER_FACTORY_HPP
#define RAYTRACER_RENDERER_FACTORY_HPP

#include "RayTracer/Abstraction/IRenderer.hpp"
#include "RayTracer/PluginLoader.hpp"

namespace RayTracer {

    class RendererFactory {
        public:
            static std::unique_ptr<IRenderer> createRenderer(const std::string &libraryPath)
            {
                return PluginLoader::loadPlugin<IRenderer>(libraryPath);
            };

    }; // class RendererFactory

} // namespace RayTracer

#endif //RAYTRACER_RENDERER_FACTORY_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | rendererFactory
** File description:
** rendererFactory.hpp
*/

#ifndef RAYTRACER_RENDERER_FACTORY_HPP
#define RAYTRACER_RENDERER_FACTORY_HPP

#include <memory>
#include <dlfcn.h>

#include "RayTracer/Abstraction/IRenderer.hpp"

namespace RayTracer {

    class RendererFactory {
        public:
            static std::unique_ptr<IRenderer> createRenderer(const std::string &libraryPath)
            {
                void *handle = dlopen(libraryPath.c_str(), RTLD_LAZY);
                if (handle == nullptr) {
                    throw std::runtime_error("Failed to load library: " + std::string(dlerror()));
                }

                auto *createRenderer = reinterpret_cast<std::unique_ptr<IRenderer>(*)()>(dlsym(handle, "entryPoint"));
                if (createRenderer == nullptr) {
                    dlclose(handle);
                    throw std::runtime_error("Failed to load symbol: " + std::string(dlerror()));
                }

                std::unique_ptr<IRenderer> renderer(createRenderer());
                if (!renderer) {
                    dlclose(handle);
                    throw std::runtime_error("Failed to create renderer");
                }

                return renderer;
            };

    }; // class RendererFactory

} // namespace RayTracer

#endif //RAYTRACER_RENDERER_FACTORY_HPP

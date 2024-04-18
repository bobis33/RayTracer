/*
** EPITECH PROJECT, 2024
** Raytracer | PluginLoader
** File description:
** PluginLoader.hpp
*/

#ifndef RAYTRACER_PLUGIN_LOADER_HPP
#define RAYTRACER_PLUGIN_LOADER_HPP

#include <memory>
#include <dlfcn.h>

#include "RayTracer/Abstraction/IRenderer.hpp"
#include "RayTracer/Exceptions/RuntimeException.hpp"

namespace RayTracer {

    class PluginLoader {
        public:
        template<typename T>
        static std::unique_ptr<T> loadPlugin(const std::string &libraryPath)
        {
            {
                void *handle = dlopen(libraryPath.c_str(), RTLD_LAZY);
                if (handle == nullptr) {
                    throw RunTimeException(dlerror());
                }
                auto *entryPointFunc = reinterpret_cast<std::unique_ptr<T> (*)()>(dlsym(handle, "entryPoint"));
                if (entryPointFunc == nullptr) {
                    throw RunTimeException(dlerror());
                }

                return entryPointFunc();
            }
        }

    }; // class PluginLoader

} // namespace RayTracer

#endif // RAYTRACER_PLUGIN_LOADER_HPP

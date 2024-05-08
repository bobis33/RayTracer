/*
** EPITECH PROJECT, 2024
** Raytracer | Loader
** File description:
** Plugin.hpp
*/

#ifndef RAYTRACER_PLUGIN_LOADER_HPP
#define RAYTRACER_PLUGIN_LOADER_HPP

#include <dlfcn.h>
#include <unordered_map>
#include <filesystem>

#include "RayTracer/Abstraction/IRenderer.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace RayTracer {

    class PluginLoader {

        public:

            using PluginCreator = std::unique_ptr<IPlugin> (*)();

            ~PluginLoader() = default;

            static PluginLoader& getInstance();

            template <typename T>
            std::unique_ptr<T> getPlugin(const std::string &pluginName);

        private:

            PluginLoader() { loadPlugins(); };

            void loadPlugins();

            std::unordered_map<std::string, PluginCreator> m_plugins;

    }; // class PluginLoader

} // namespace RayTracer

#endif // RAYTRACER_PLUGIN_LOADER_HPP

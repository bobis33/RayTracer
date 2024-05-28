/*
** EPITECH PROJECT, 2024
** Raytracer | Loader
** File description:
** Plugin.hpp
*/

/// @file Plugin.hpp
#ifndef RAYTRACER_PLUGIN_LOADER_HPP
#define RAYTRACER_PLUGIN_LOADER_HPP

#include <dlfcn.h>
#include <unordered_map>
#include <filesystem>

#include "RayTracer/Abstraction/IRenderer.hpp"
#include "RayTracer/Exception/RunTime.hpp"

namespace rtr {

    /// @class PluginLoader
    /// @brief A class to load the plugins.
    class PluginLoader {

        public:

            using PluginCreator = std::unique_ptr<IPlugin> (*)();

            ~PluginLoader() = default;

            /// @brief Gets the instance of the plugin loader.
            /// @return A reference to the plugin loader.
            static PluginLoader &getInstance() {
                static PluginLoader instance;
                return instance;
            }

            /// @brief Gets the plugin based on the name.
            /// @param pluginName The name of the plugin.
            template <typename T>
            std::unique_ptr<T> getPlugin(const std::string &pluginName);

            void closePlugins() {
                for (void* handle : m_handles) {
                        dlclose(handle);
                }
            }

        private:

            PluginLoader() { loadPlugins(); };

            /// @brief Loads the plugins.
            void loadPlugins();

            /// @brief Gets the plugin creator based on the name in an unordered map because it is not necessary to have an index.
            std::unordered_map<std::string, PluginCreator> m_plugins{};
            std::vector<void *> m_handles{};

    }; // class PluginLoader

} // namespace RayTracer

#endif // RAYTRACER_PLUGIN_LOADER_HPP

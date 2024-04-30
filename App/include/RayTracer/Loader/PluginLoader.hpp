/*
** EPITECH PROJECT, 2024
** Raytracer | PluginLoader
** File description:
** PluginLoader.hpp
*/

#ifndef RAYTRACER_PLUGIN_LOADER_HPP
#define RAYTRACER_PLUGIN_LOADER_HPP

#include <dlfcn.h>
#include <unordered_map>
#include <filesystem>

#include "RayTracer/Abstraction/IRenderer.hpp"
#include "RayTracer/Exceptions/RuntimeException.hpp"

namespace RayTracer {

    class PluginLoader {

        public:
            using PluginCreator = std::unique_ptr<IPlugin> (*)();

            static PluginLoader& getInstance() {
                static PluginLoader instance;
                return instance;
            }

            template <typename T>
            std::unique_ptr<T> getPlugin(const std::string &pluginName) {
                auto plugin_iterator = m_plugins.find(pluginName);
                if (plugin_iterator == m_plugins.end()) {
                    throw RunTimeException("Plugin not found");
                }
                PluginCreator creator = plugin_iterator->second;
                if constexpr (std::is_base_of_v<IPlugin, T>) {
                    return std::unique_ptr<T>(static_cast<T*>(creator().release()));
                } else {
                    throw RunTimeException("Invalid plugin type");
                }
            }

        private:
            PluginLoader() { loadPlugins(); };

            void loadPlugins() {
                for (const auto& entry : std::filesystem::directory_iterator("./plugins")) {
                    if (entry.path().extension() == ".so") {
                        void* handle = dlopen(entry.path().c_str(), RTLD_LAZY);
                        if (handle == nullptr) {
                            throw RunTimeException(dlerror());
                        }
                        auto creator = reinterpret_cast<PluginCreator>(dlsym(handle, "entryPoint"));
                        if (creator == nullptr) {
                            dlclose(handle);
                            throw RunTimeException(dlerror());
                        }
                        m_plugins.emplace(creator()->getPluginName(), creator);
                    }
                }
            }

            std::unordered_map<std::string, PluginCreator> m_plugins;

    }; // class PluginLoader

} // namespace RayTracer

#endif // RAYTRACER_PLUGIN_LOADER_HPP

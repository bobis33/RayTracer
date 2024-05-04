/*
** EPITECH PROJECT, 2024
** raytracer | Loader
** File description:
** plugin.cpp
*/

#include "RayTracer/Loader/Plugin.hpp"
#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Abstraction/AShape.hpp"

void RayTracer::PluginLoader::loadPlugins() {
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

RayTracer::PluginLoader &RayTracer::PluginLoader::getInstance() {
    static PluginLoader instance;
    return instance;
}


template <typename T>
std::unique_ptr<T> RayTracer::PluginLoader::getPlugin(const std::string &pluginName) {
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
template std::unique_ptr<RayTracer::ALight> RayTracer::PluginLoader::getPlugin<RayTracer::ALight>(const std::string &pluginName);
template std::unique_ptr<RayTracer::ARenderer> RayTracer::PluginLoader::getPlugin<RayTracer::ARenderer>(const std::string &pluginName);
template std::unique_ptr<RayTracer::AShape> RayTracer::PluginLoader::getPlugin<RayTracer::AShape>(const std::string &pluginName);
template std::unique_ptr<RayTracer::AMaterial> RayTracer::PluginLoader::getPlugin<RayTracer::AMaterial>(const std::string &pluginName);

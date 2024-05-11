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

void rtr::PluginLoader::loadPlugins() {
    void *handle = nullptr;

    for (const auto& entry : std::filesystem::directory_iterator("./plugins")) {
        if (entry.path().extension() == ".so") {
            handle = dlopen(entry.path().c_str(), RTLD_LAZY);
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

template <typename T>
std::unique_ptr<T> rtr::PluginLoader::getPlugin(const std::string &pluginName) {
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
template std::unique_ptr<rtr::ALight> rtr::PluginLoader::getPlugin<rtr::ALight>(const std::string &pluginName);
template std::unique_ptr<rtr::ARenderer> rtr::PluginLoader::getPlugin<rtr::ARenderer>(const std::string &pluginName);
template std::unique_ptr<rtr::AShape> rtr::PluginLoader::getPlugin<rtr::AShape>(const std::string &pluginName);
template std::unique_ptr<rtr::AMaterial> rtr::PluginLoader::getPlugin<rtr::AMaterial>(const std::string &pluginName);

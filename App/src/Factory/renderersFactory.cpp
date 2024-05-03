/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** renderersFactory.cpp
*/

#include "RayTracer/Factory/RenderersFactory.hpp"

std::unique_ptr<RayTracer::ARenderer> RayTracer::RenderersFactory::createRenderer(const RendererType &type,
                                                                                  const std::string &name,
                                                                                  const Resolution &resolution)
{
    std::unique_ptr<ARenderer> renderer;
    switch (type) {
        case RendererType::PPM:
            renderer = PluginLoader::getInstance().getPlugin<ARenderer>(PPM_RENDERER);
            break;
        case RendererType::SFML:
            renderer = PluginLoader::getInstance().getPlugin<ARenderer>(SFML_RENDERER);
            break;
        default:
            throw RunTimeException("Renderer type not found");
    }
    renderer->setType(type);
    renderer->getResolution().setResolution(resolution.getValue());
    renderer->setName(name);
    return renderer;
};
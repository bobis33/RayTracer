/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** renderer.cpp
*/

#include "RayTracer/Factory/Renderer.hpp"

std::unique_ptr<rtr::ARenderer> rtr::RendererFactory::createRenderer(const RendererType &type,
                                                                     const std::string &name,
                                                                     const Resolution &resolution,
                                                                     const Color &backgroundColor)
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
    renderer->getBackgroundColor().setColor(backgroundColor.getValue());
    return renderer;
};
/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** renderer
*/

#include "RayTracer/Parser.hpp"

void RayTracer::Parser::parseRenderer(const libconfig::Setting &renderer, Scene &scene)
{
    const std::string &rendererType = renderer["type"];
    RendererType type(RendererType::NONE);
    if (rendererType == "sfml") {
        type = RendererType::SFML;
    } else if (rendererType == "ppm") {
        type = RendererType::PPM;
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    int width = renderer["width"];
    int height = renderer["height"];
    scene.setRenderer(RenderersFactory::createRenderer(type, renderer["fileName"], Resolution(static_cast<uint16_t>(width), static_cast<uint16_t>(height))));
}
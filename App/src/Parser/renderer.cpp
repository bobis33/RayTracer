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
    const libconfig::Setting &resolution = renderer["resolution"];
    RendererType type(RendererType::NONE);
    if (rendererType == "sfml") {
        type = RendererType::SFML;
    } else if (rendererType == "ppm") {
        type = RendererType::PPM;
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    scene.setRenderer(RenderersFactory::createRenderer(type,
                                                       renderer["name"],
                                                       Resolution(convertInt<uint16_t>(resolution[0]),
                                                                  convertInt<uint16_t>(resolution[1]))));
}
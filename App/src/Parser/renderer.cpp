/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** renderer.cpp
*/

#include "RayTracer/Parser.hpp"

void RayTracer::Parser::parseRenderer(const libconfig::Setting &renderer, Scene &scene)
{
    const std::string &type = renderer["type"];
    const libconfig::Setting &resolution = renderer["resolution"];
    RendererType rendererType = RendererType::NONE;
    if (type == "sfml") {
        rendererType = RendererType::SFML;
    } else if (type == "ppm") {
        rendererType = RendererType::PPM;
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    scene.setRenderer(
            RendererFactory::createRenderer(
                    rendererType,
                    renderer["name"],
                    Resolution(convertInt<uint16_t>(resolution[0]), convertInt<uint16_t>(resolution[1])),
                    Color(getVector<Color>(renderer["backgroundColor"], convertInt<uint8_t>))));
}
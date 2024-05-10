/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** renderer.cpp
*/

#include "RayTracer/Parser.hpp"

void rtr::Parser::parseRenderer(const libconfig::Setting &renderer, Scene &scene)
{
    if (!renderer.exists("type")) {
        throw ParserException{"Renderer must have a type setting."};
    }
    const std::string &type = renderer["type"];
    if (!renderer.exists("resolution")) {
        throw ParserException{"Renderer must have a resolution setting."};
    }
    const libconfig::Setting &resolution = renderer["resolution"];
    Resolution res(convertInt<uint16_t>(resolution[0]), convertInt<uint16_t>(resolution[1]));
    RendererType rendererType(RendererType::NONE);
    if (type == "sfml") {
        rendererType = RendererType::SFML;
    } else if (type == "ppm") {
        rendererType = RendererType::PPM;
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    if (!renderer.exists("name")) {
        throw ParserException{"Renderer must have a name setting."};
    }
    const std::string &name = renderer["name"];
    if (!renderer.exists("backgroundColor")) {
        throw ParserException{"Renderer must have a background color setting."};
    }
    Color color(getVector<Color>(renderer["backgroundColor"], convertInt<uint8_t>));
    scene.setRenderer(RendererFactory::createRenderer(rendererType, name, res, color));
}
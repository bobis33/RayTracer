/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** renderer.cpp
*/

#include "RayTracer/Parser.hpp"

void rtr::Parser::parseRenderer(const libconfig::Setting &renderer, Scene &scene)
{
    if (!renderer.exists("type") || !renderer.exists("resolution") || !renderer.exists("name") || !renderer.exists("backgroundColor")) {
        throw ParserException{"Renderer must have a type, a resolution, a name and a background color setting."};
    }
    const std::string &type = renderer["type"];
    RendererType rendererType = RendererType::NONE;
    if (type == "sfml") {
        rendererType = RendererType::SFML;
    } else if (type == "ppm") {
        rendererType = RendererType::PPM;
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    scene.setRenderer(RendererFactory::createRenderer(
            rendererType,
            renderer["name"],
            Resolution{convertInt<uint16_t>(renderer["resolution"][0]), convertInt<uint16_t>(renderer["resolution"][1])},
            getVector<Color>(renderer["backgroundColor"], convertInt<uint8_t>)));
}
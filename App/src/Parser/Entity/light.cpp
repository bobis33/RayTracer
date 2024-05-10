/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** light.cpp
*/

#include "RayTracer/Parser.hpp"
#include "RayTracer/Factory/Light.hpp"

rtr::LightType rtr::Parser::parseLightType(const std::string &type)
{
    if (type == "ambient") {
        return LightType::AMBIENT;
    } else if (type == "directional") {
        return LightType::DIRECTIONAL;
    } else if (type == "point") {
        return LightType::POINT;
    }
    throw ParserException{"Invalid light type"};
}

void rtr::Parser::parseLights(const libconfig::Setting &lightsSetting, Scene &scene)
{
    for (int i = 0; i < lightsSetting.getLength(); i++) {
        const libconfig::Setting &light = lightsSetting[i];
        if (!light.exists("type")) {
            throw ParserException{"Lights must have a type setting."};
        }
        LightType lightType(parseLightType(light["type"]));

        if (!light.exists("color")) {
            throw ParserException{"Lights must have a color setting."};
        }
        Color color(getVector<Color>(light["color"], convertInt<uint8_t>));

        if (!light.exists("intensity")) {
            throw ParserException{"Lights must have an intensity setting."};
        }
        float intensity = light["intensity"];

        switch (lightType) {
            case LightType::AMBIENT: {
                scene.addLight(LightFactory::createLight(color, intensity));
                break;
            }
            case LightType::POINT: {
                if (!light.exists("position")) {
                    throw ParserException{"Point lights must have a position setting."};
                }
                Vector position(getVector<Vector>(light["position"], convertInt<double>));
                scene.addLight(LightFactory::createLight(color, intensity, position));
                break;
            }
            case LightType::DIRECTIONAL: {
                if (!light.exists("position") || !light.exists("direction")) {
                    throw ParserException{"Directional lights must have a position and direction setting."};
                }
                Vector position(getVector<Vector>(light["position"], convertInt<double>));
                Vector direction(getVector<Vector>(light["direction"], convertInt<double>));
                scene.addLight(LightFactory::createLight(color, intensity, direction, position));
                break;
            }
            default:
                throw ParserException{"Invalid light type"};
        }
    }
}
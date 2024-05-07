/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** light.cpp
*/

#include "RayTracer/Parser.hpp"
#include "RayTracer/Factory/Light.hpp"

RayTracer::LightType RayTracer::Parser::parseLightType(const std::string &type)
{
    if (type == "ambient") {
        return LightType::AMBIENT;
    } else if (type == "point") {
        return LightType::POINT;
    } else if (type == "directional") {
        return LightType::DIRECTIONAL;
    }
    throw ParserException{"Invalid light type"};
}

void RayTracer::Parser::parseLights(const libconfig::Setting &lightsSetting, Scene &scene)
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
            case LightType::AMBIENT:
                scene.addLight(LightFactory::createLight(LightType::AMBIENT, intensity));
                break;
            case LightType::POINT:
            case LightType::DIRECTIONAL: {
                if (!light.exists("position")) {
                    throw ParserException{"Point lights must have a position setting."};
                }
                Vector position(getVector<Vector>(light["position"], convertInt<double>));
                if (!light.exists("direction")) {
                    throw ParserException{"Directional lights must have a direction setting."};
                }
                Vector direction(getVector<Vector>(light["direction"], convertInt<double>));
                scene.addLight(LightFactory::createLight(lightType, color, intensity, direction));
                break;
            }
            default:
                throw ParserException{"Invalid light type"};
        }
    }
}
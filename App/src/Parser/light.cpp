/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** light.cpp
*/

#include "RayTracer/Parser.hpp"
#include "RayTracer/Factory/Light.hpp"

void RayTracer::Parser::parseLights(const libconfig::Setting &lightsSetting, Scene &scene)
{
    for (int i = 0; i < lightsSetting.getLength(); i++) {
        const libconfig::Setting &light = lightsSetting[i];
        if (!light.exists("type")) {
            throw ParserException{"Lights must have a type setting."};
        }
        std::string type = light["type"];
        if (!light.exists("position")) {
            throw ParserException{"Lights must have a position setting."};
        }
        Vector position(getVector<Vector>(light["position"], convertInt<int16_t>));
        if (!light.exists("color")) {
            throw ParserException{"Lights must have a color setting."};
        }
        Color color(getVector<Color>(light["color"], convertInt<uint8_t>));
        if (!light.exists("intensity")) {
            throw ParserException{"Lights must have an intensity setting."};
        }
        float intensity = light["intensity"];

        if (type == "point") {
            scene.addLight(LightFactory::createLight(LightType::POINT, position, color, intensity));
        } else if (type == "ambient") {
            scene.addLight(LightFactory::createLight(LightType::AMBIENT, position, color, intensity));
        } else if (type == "directional") {
            if (!light.exists("direction")) {
                throw ParserException{"Directional lights must have a direction setting."};
            }
            Vector direction(getVector<Vector>(light["direction"], convertInt<int16_t>));
            scene.addLight(LightFactory::createLight(position, color, intensity, direction));
        } else {
            throw ParserException{"Invalid light type"};
        }
    }
}
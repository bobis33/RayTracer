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
        const libconfig::Setting &Light = lightsSetting[i];
        std::string type = Light["type"];
        Vector position(getVector<Vector>(Light["position"], convertInt<int16_t>));
        Color color(getVector<Color>(Light["color"], convertInt<uint8_t>));
        float intensity = Light["intensity"];

        if (type == "point") {
            scene.addLight(LightFactory::createLight(LightType::POINT, position, color, intensity));
        } else if (type == "ambient") {
            scene.addLight(LightFactory::createLight(LightType::AMBIENT, position, color, intensity));
        } else if (type == "directional") {
            scene.addLight(LightFactory::createLight(position, color, intensity, Vector(getVector<Vector>(Light["direction"], convertInt<int16_t>))));
        } else {
            throw ParserException{"Invalid light type"};
        }
    }
}
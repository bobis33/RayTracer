/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** light
*/

#include "RayTracer/Parser.hpp"
#include "RayTracer/Factory/LightsFactory.hpp"

void RayTracer::Parser::parseLights(const libconfig::Setting &lightsSetting, Scene &scene)
{
    for (int i = 0; i < lightsSetting.getLength(); i++) {
        const libconfig::Setting &Light = lightsSetting[i];
        std::string type = Light["type"];
        Vector position(getVector(Light["position"]));
        Color color(convertInt<uint8_t>(Light["color"][0]), convertInt<uint8_t>(Light["color"][1]), convertInt<uint8_t>(Light["color"][2]));
        // float intensity = Light["intensity"];

        if (type == "point") {
            scene.addLight(LightsFactory::createLights(LightType::POINT, position, color));
        } else if (type == "ambient") {
            scene.addLight(LightsFactory::createLights(LightType::AMBIENT, position, color));
        } else if (type == "directional") {
            // Vector direction(getVector(Light["direction"]));
            scene.addLight(LightsFactory::createLights(LightType::DIRECTIONAL, position, color));
        } else {
            throw ParserException{"Invalid light type"};
        }
    }
}
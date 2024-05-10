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
    } if (type == "directional") {
        return LightType::DIRECTIONAL;
    } if (type == "point") {
        return LightType::POINT;
    }
    throw ParserException{"Invalid light type"};
}

void rtr::Parser::parseLights(const libconfig::Setting &lightsSetting, Scene &scene)
{
    Color color = Color{};
    LightType lightType = LightType::NONE;
    float intensity = 0;

    for (int i = 0; i < lightsSetting.getLength(); i++) {
        const libconfig::Setting &light = lightsSetting[i];
        if (!light.exists("type") || !light.exists("color") || !light.exists("intensity")){
            throw ParserException{"Lights must have a type, a color and an intensity setting."};
        }
        lightType = parseLightType(light["type"]);
        color = getVector<Color>(light["color"], convertInt<uint8_t>);
        intensity = light["intensity"];

        switch (lightType) {
            case LightType::AMBIENT: {
                scene.addLight(LightFactory::createLight(color, intensity));
                break;
            }
            case LightType::POINT: {
                if (!light.exists("position")) {
                    throw ParserException{"Point lights must have a position setting."};
                }
                scene.addLight(LightFactory::createLight(LightType::POINT, color, intensity, getVector<Vector>(light["position"], convertInt<double>)));
                break;
            }
            case LightType::DIRECTIONAL: {
                if (!light.exists("direction")) {
                    throw ParserException{"Directional lights must have a direction setting."};
                }
                scene.addLight(LightFactory::createLight(LightType::DIRECTIONAL, color, intensity, getVector<Vector>(light["direction"], convertInt<double>)));
                break;
            }
            default:
                throw ParserException{"Invalid light type"};
        }
    }
}
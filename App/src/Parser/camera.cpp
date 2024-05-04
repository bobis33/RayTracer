/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** camera.cpp
*/

#include "RayTracer/Parser.hpp"

void RayTracer::Parser::parseCamera(const libconfig::Setting &camera, Scene &scene)
{
    const libconfig::Setting &cameraFov = camera["fov"];
    std::vector<libconfig::Setting *> settings = {&camera["origin"], &camera["direction"], &camera["up"]};
    for (const auto &setting : settings) {
        if (setting->getLength() != 3 || setting->getType() != libconfig::Setting::TypeArray) {
            throw ParserException{"Invalid camera settings: Wrong amount of values or wrong type"};
        }
    }
    scene.setCamera(Camera(convertInt<uint16_t>(cameraFov),
                    Vector(convertInt<int16_t>(camera["origin"][0]), convertInt<int16_t>(camera["origin"][1]), convertInt<int16_t>(camera["origin"][2])),
                    Vector(convertInt<int16_t>(camera["direction"][0]), convertInt<int16_t>(camera["direction"][1]), convertInt<int16_t>(camera["direction"][2])),
                    Vector(convertInt<int16_t>(camera["up"][0]), convertInt<int16_t>(camera["up"][1]), convertInt<int16_t>(camera["up"][2]))));
}

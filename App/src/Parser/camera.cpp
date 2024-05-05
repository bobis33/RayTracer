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
    for (const auto &setting : {&camera["origin"], &camera["direction"], &camera["up"]}) {
        if (setting->getLength() != 3 || setting->getType() != libconfig::Setting::TypeArray) {
            throw ParserException{"Invalid camera settings: Wrong amount of values or wrong type"};
        }
    }
    scene.setCamera(Camera(convertInt<uint16_t>(cameraFov),
                    Vector(getVector<Vector>(camera["origin"], convertInt<int16_t>)),
                    Vector(getVector<Vector>(camera["direction"], convertInt<int16_t>)),
                    Vector(getVector<Vector>(camera["up"], convertInt<int16_t>))));
}

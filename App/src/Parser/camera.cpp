/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** camera.cpp
*/

#include "RayTracer/Parser.hpp"

void RayTracer::Parser::parseCamera(const libconfig::Setting &camera, Scene &scene)
{
    if (!camera.exists("fov")){
        throw ParserException{"Camera must have a fov setting."};
    }
    const libconfig::Setting &cameraFov = camera["fov"];
    if (!camera.exists("origin") || !camera.exists("direction") || !camera.exists("up")) {
        throw ParserException{"Camera must have origin, direction and up settings."};
    }
    for (const auto &setting : {&camera["origin"], &camera["direction"], &camera["up"]}) {
        if (setting->getLength() != 3 || setting->getType() != libconfig::Setting::TypeArray) {
            throw ParserException{"Invalid camera settings: Wrong amount of values or wrong type."};
        }
    }
    scene.setCamera(Camera(convertInt<uint16_t>(cameraFov),
                    Vector(getVector<Vector>(camera["origin"], convertInt<double>)),
                    Vector(getVector<Vector>(camera["direction"], convertInt<double>)),
                    Vector(getVector<Vector>(camera["up"], convertInt<double>))));
}

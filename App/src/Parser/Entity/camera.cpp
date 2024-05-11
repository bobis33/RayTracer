/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** camera.cpp
*/

#include "RayTracer/Parser.hpp"

void rtr::Parser::parseCamera(const libconfig::Setting &camera, Scene &scene)
{
    if (!camera.exists("origin") || !camera.exists("direction") || !camera.exists("fov")) {
        throw ParserException{"Camera must have origin, direction and fov settings."};
    }
    for (const auto &setting : {&camera["origin"], &camera["direction"]}) {
        if (setting->getLength() != 3 || setting->getType() != libconfig::Setting::TypeArray) {
            throw ParserException{"Invalid camera settings: Wrong amount of values or wrong type."};
        }
    }
    scene.setCamera(Camera(convertInt<uint16_t>(camera["fov"]),
                    Vector(getVector<Vector>(camera["origin"], convertInt<double>)),
                    Vector(getVector<Vector>(camera["direction"], convertInt<double>))));
}

/*
** EPITECH PROJECT, 2024
** Raytracer | parser
** File description:
** Parser.cpp
*/

#include <filesystem>

#include "RayTracer/Factory/Light.hpp"
#include "RayTracer/Parser.hpp"
#include "RayTracer/Scene/Camera.hpp"

RayTracer::Vector RayTracer::Parser::getVector(const libconfig::Setting &positionSettings)
{
    if (positionSettings.getLength() != 3 || positionSettings.getType() != libconfig::Setting::TypeArray) {
        throw ParserException{"Invalid position settings: Wrong amount of values or wrong type"};
    }

    return {convertInt<int16_t>(positionSettings[0]), convertInt<int16_t>(positionSettings[1]), convertInt<int16_t>(positionSettings[2])};
}

std::unique_ptr<RayTracer::Scene> RayTracer::Parser::parseFile(const std::string &filePath)
{
    libconfig::Config cfg;
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    try {
        cfg.readFile(filePath.c_str());
        libconfig::Setting& root = cfg.getRoot();
        parseRenderer(root["renderer"], *scene);
        parseCamera(root["camera"], *scene);
        parseShapes(root["shapes"], *scene);
        parseLights(root["lights"], *scene);
    } catch (const libconfig::FileIOException &e) {
        throw ParserException{"Error while reading file"};
    } catch (const libconfig::ParseException &e) {
        throw ParserException{e.getError()};
    }

    return scene;
}

int RayTracer::Parser::parseArgs(const std::string &filePath)
{
    if (filePath == "--help") {
        std::cout << "USAGE:  ./raytracer <SCENE_FILE>\n"
                     "  SCENE_FILE: scene configuration" << '\n';
        return ERROR;
    }

    std::filesystem::path path{filePath};
    if (!std::filesystem::exists(path)) {
        throw ParserException{"File does not exist"};
    }
    return SUCCESS;
}

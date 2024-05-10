/*
** EPITECH PROJECT, 2024
** Raytracer | parser
** File description:
** Parser.cpp
*/

#include "RayTracer/Parser.hpp"

std::unique_ptr<rtr::Scene> rtr::Parser::parseFile(const std::string &filePath)
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
        throw ParserException{"Error while reading file."};
    } catch (const libconfig::ParseException &e) {
        throw ParserException{e.getError()};
    }

    return scene;
}

int rtr::Parser::parseArgs(const std::string &filePath)
{
    if (filePath == "--help") {
        std::cout << "USAGE:  ./raytracer <SCENE_FILE>\n"
                     "  SCENE_FILE: scene configuration" << '\n';
        return ERROR;
    }

    if (!std::filesystem::exists(std::filesystem::path{filePath})) {
        throw ParserException{"File does not exists."};
    }
    return SUCCESS;
}

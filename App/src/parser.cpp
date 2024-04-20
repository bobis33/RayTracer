/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#include <filesystem>

#include "RayTracer/Parser.hpp"

void RayTracer::Parser::parseRenderer(const libconfig::Setting &renderer, Scene &scene)
{
    const std::string &rendererType = renderer["type"];
    if (rendererType == "sfml") {
        scene.setRenderer(RendererType::SFML);
    } else if (rendererType == "ppm") {
        scene.setRenderer(RendererType::PPM);
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    scene.setName(renderer["fileName"]);
    int width = renderer["width"];
    int height = renderer["height"];
    scene.setResolution({static_cast<uint16_t>(width), static_cast<uint16_t>(height)});
}

std::unique_ptr<RayTracer::Scene> RayTracer::Parser::parseFile(const std::string &filePath)
{
    libconfig::Config cfg;
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    try {
        cfg.readFile(filePath.c_str());
        libconfig::Setting& root = cfg.getRoot();
        parseRenderer(root["renderer"], *scene);
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

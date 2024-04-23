/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#include <filesystem>

#include "RayTracer/Parser.hpp"
#include "../plugins/Shapes/Plane/include/RayTracer/PlaneShape.hpp"

void RayTracer::Parser::parseRenderer(const libconfig::Setting &renderer, Scene &scene)
{
    const std::string &rendererType = renderer["type"];
    RendererType type{RendererType::NONE};
    if (rendererType == "sfml") {
        type = RendererType::SFML;
    } else if (rendererType == "ppm") {
        type = RendererType::PPM;
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    const std::string &name = renderer["fileName"];
    int width = renderer["width"];
    int height = renderer["height"];
    resolution_t resolution = {static_cast<uint16_t>(width), static_cast<uint16_t>(height)};
    scene.setRenderer(RendererFactory::createRenderer(type, name, resolution));
}


void RayTracer::Parser::parseShapes(const libconfig::Setting &shapesSetting, Scene &scene)
{
    for (int i = 0; i < shapesSetting.getLength(); ++i) {
        const libconfig::Setting &shapeSetting = shapesSetting[i];
        std::string type = shapeSetting["type"];
        if (type == "plane") {
            libconfig::Setting &positionSetting = shapeSetting["position"];
            libconfig::Setting &normalSetting = shapeSetting["normal"];
            libconfig::Setting &distanceSetting = shapeSetting["distance"];
            libconfig::Setting &materialSetting = shapeSetting["material"];

            Vector3D position(positionSetting[0], positionSetting[1], positionSetting[2]);
            Vector3D normal(normalSetting[0], normalSetting[1], normalSetting[2]);
            double distance = distanceSetting;
            std::string material = materialSetting;

            scene.addShape(std::make_unique<RayTracer::PlaneShape>(position, normal, distance, material));
        } else {
            throw ParserException{"Invalid shape type"};
        }
    }
}

std::unique_ptr<RayTracer::Scene> RayTracer::Parser::parseFile(const std::string &filePath)
{
    libconfig::Config cfg;
    std::unique_ptr<Scene> scene = std::make_unique<Scene>();
    try {
        cfg.readFile(filePath.c_str());
        libconfig::Setting& root = cfg.getRoot();
        parseRenderer(root["renderer"], *scene);
        parseShapes(root["shapes"], *scene);
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

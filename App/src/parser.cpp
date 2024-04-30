/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#include <filesystem>

#include "RayTracer/Parser.hpp"
#include "RayTracer/Factory/ShapesFactory.hpp"

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

int16_t RayTracer::Parser::getDouble(const libconfig::Setting &setting)
{
    if (setting.getType() == libconfig::Setting::Type::TypeInt) {
        int value = setting;
        return static_cast<int16_t>(value);
    } else if (setting.getType() == libconfig::Setting::Type::TypeInt64) {
        long long value = setting;
        return static_cast<int16_t>(value);
    }
    throw ParserException{"Invalid setting type"};
}

void RayTracer::Parser::parseShapes(const libconfig::Setting &shapesSetting, Scene &scene)
{
    (void)scene;
    for (int i = 0; i < shapesSetting.getLength(); ++i) {
        const libconfig::Setting &shapeSetting = shapesSetting[i];
        std::string type = shapeSetting["type"];
        if (type == "plane") {
            libconfig::Setting &positionSetting = shapeSetting["position"];
            if (positionSetting.getLength() != 3 || positionSetting.getType() != libconfig::Setting::TypeArray) {
                throw ParserException{"Invalid shape setting"};
            }
            vector_t pos = {getDouble(positionSetting[0]), getDouble(positionSetting[1]), getDouble(positionSetting[2])};
            scene.addShape(ShapesFactory::createShape(ShapeType::PLANE, pos));
        } else {
            throw ParserException{"Invalid shape type"};
        }
        std::cout << "Out of Parsing" << std::endl;
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

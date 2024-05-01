/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#include <filesystem>

#include "RayTracer/Factory/ShapesFactory.hpp"
#include "RayTracer/Parser.hpp"
#include "RayTracer/Scene/Camera.hpp"

template<typename T>
T RayTracer::Parser::convertInt(const libconfig::Setting &setting)
{
    if (setting.getType() == libconfig::Setting::Type::TypeInt) {
        int value = setting;
        return static_cast<T>(value);
    }
    throw ParserException{"Invalid setting type"};
}

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

void RayTracer::Parser::parseCamera(const libconfig::Setting &camera, Scene &scene)
{
    const libconfig::Setting &cameraFov = camera["fov"];
    std::vector<libconfig::Setting *> settings = {&camera["origin"], &camera["lookAt"], &camera["up"]};
    for (const auto &setting : settings) {
        if (setting->getLength() != 3 || setting->getType() != libconfig::Setting::TypeArray) {
            throw ParserException{"Invalid camera settings: Wrong amount of values or wrong type"};
        }
    }
    if (cameraFov.getType() != libconfig::Setting::TypeInt) {
        throw ParserException{"Invalid camera settings: Wrong fov type"};
    }

    Vector origin = {convertInt<int16_t>(camera["origin"][0]), convertInt<int16_t>(camera["origin"][1]), convertInt<int16_t>(camera["origin"][2])};
    Vector direction = {convertInt<int16_t>(camera["lookAt"][0]), convertInt<int16_t>(camera["lookAt"][1]), convertInt<int16_t>(camera["lookAt"][2])};
    Vector up = {convertInt<int16_t>(camera["up"][0]), convertInt<int16_t>(camera["up"][1]), convertInt<int16_t>(camera["up"][2])};
    uint16_t fov = convertInt<uint16_t>(cameraFov);

    scene.setCamera(Camera(fov, origin, direction, up));
}

void RayTracer::Parser::parseShapes(const libconfig::Setting &shapesSetting, Scene &scene)
{
    for (int i = 0; i < shapesSetting.getLength(); ++i) {
        const libconfig::Setting &shapeSetting = shapesSetting[i];
        std::string type = shapeSetting["type"];
        libconfig::Setting &positionSetting = shapeSetting["position"];
        if (positionSetting.getLength() != 3 || positionSetting.getType() != libconfig::Setting::TypeArray) {
            throw ParserException{"Invalid shape settings: Wrong amount of position values or wrong type"};
        }
        vector_t pos = {convertInt<int16_t>(positionSetting[0]), convertInt<int16_t>(positionSetting[1]), convertInt<int16_t>(positionSetting[2])};

        if (type == "plane") {
            scene.addShape(ShapesFactory::createShape(ShapeType::PLANE, pos));

        } else if (type == "sphere" || type == "cylinder" || type == "cone") {
            libconfig::Setting &radiusSetting = shapeSetting["radius"];
            int16_t radius = convertInt<int16_t>(radiusSetting);
            if (type == "sphere") {
                scene.addShape(ShapesFactory::createShape(ShapeType::SPHERE, pos, radius));
            } else if (type == "cylinder") {
                scene.addShape(ShapesFactory::createShape(ShapeType::CYLINDER, pos, radius));
            } else if (type == "cone") {
                scene.addShape(ShapesFactory::createShape(ShapeType::CONE, pos, radius));
            }
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
        parseCamera(root["camera"], *scene);
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

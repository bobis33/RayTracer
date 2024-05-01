/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Parser.cpp
*/

#include <filesystem>

#include "RayTracer/Factory/LightsFactory.hpp"
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
    throw ParserException{"Invalid setting type (Integer)"};
}

RayTracer::Vector RayTracer::Parser::getVector(const libconfig::Setting &positionSettings)
{
    if (positionSettings.getLength() != 3 || positionSettings.getType() != libconfig::Setting::TypeArray) {
        throw ParserException{"Invalid position settings: Wrong amount of values or wrong type"};
    }

    return {convertInt<int16_t>(positionSettings[0]), convertInt<int16_t>(positionSettings[1]), convertInt<int16_t>(positionSettings[2])};
}


void RayTracer::Parser::parseRenderer(const libconfig::Setting &renderer, Scene &scene)
{
    const std::string &rendererType = renderer["type"];
    RendererType type(RendererType::NONE);
    if (rendererType == "sfml") {
        type = RendererType::SFML;
    } else if (rendererType == "ppm") {
        type = RendererType::PPM;
    } else {
        throw ParserException{"Invalid renderer type"};
    }
    int width = renderer["width"];
    int height = renderer["height"];
    scene.setRenderer(RenderersFactory::createRenderer(type, renderer["fileName"], Resolution(static_cast<uint16_t>(width), static_cast<uint16_t>(height))));
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
    Vector origin(convertInt<int16_t>(camera["origin"][0]), convertInt<int16_t>(camera["origin"][1]), convertInt<int16_t>(camera["origin"][2]));
    Vector direction(convertInt<int16_t>(camera["lookAt"][0]), convertInt<int16_t>(camera["lookAt"][1]), convertInt<int16_t>(camera["lookAt"][2]));
    Vector up(convertInt<int16_t>(camera["up"][0]), convertInt<int16_t>(camera["up"][1]), convertInt<int16_t>(camera["up"][2]));

    scene.setCamera(Camera(convertInt<uint16_t>(cameraFov), origin, direction, up));
}

void RayTracer::Parser::parseShapes(const libconfig::Setting &shapesSetting, Scene &scene)
{
    for (int i = 0; i < shapesSetting.getLength(); i++) {
        const libconfig::Setting &shapeSetting = shapesSetting[i];
        libconfig::Setting &materialSetting = shapeSetting["material"];
        std::string type = shapeSetting["type"];
        Vector position(getVector(shapeSetting["position"]));
        Color color(convertInt<uint8_t>(materialSetting["color"][0]), convertInt<uint8_t>(materialSetting["color"][1]), convertInt<uint8_t>(materialSetting["color"][2]));
        // float reflection = materialSetting["reflectivity"];
        // float transparency = materialSetting["transparency"];

        if (type == "plane") {
            scene.addShape(ShapesFactory::createShape(ShapeType::PLANE, position));
        } else if (type == "sphere" || type == "cylinder" || type == "cone") {
            libconfig::Setting &radiusSetting = shapeSetting["radius"];
            int16_t radius = convertInt<int16_t>(radiusSetting);
            if (type == "sphere") {
                scene.addShape(ShapesFactory::createShape(ShapeType::SPHERE, position, radius));
            } else if (type == "cylinder") {
                // Vector rotation = getVector(shapeSetting["rotation"]);
                scene.addShape(ShapesFactory::createShape(ShapeType::CYLINDER, position, radius));
            } else if (type == "cone") {
                // Vector rotation = getVector(shapeSetting["rotation"]);
                scene.addShape(ShapesFactory::createShape(ShapeType::CONE, position, radius));
            }
        } else {
            throw ParserException{"Invalid shape type"};
        }
    }
}

void RayTracer::Parser::parseLights(const libconfig::Setting &lightsSetting, Scene &scene)
{
    for (int i = 0; i < lightsSetting.getLength(); i++) {
        const libconfig::Setting &Light = lightsSetting[i];
        std::string type = Light["type"];
        Vector position(getVector(Light["position"]));
        Color color(convertInt<uint8_t>(Light["color"][0]), convertInt<uint8_t>(Light["color"][1]), convertInt<uint8_t>(Light["color"][2]));
        // float intensity = Light["intensity"];

        if (type == "point") {
            scene.addLight(LightsFactory::createLights(LightType::POINT, position, color));
        } else if (type == "ambient") {
            scene.addLight(LightsFactory::createLights(LightType::AMBIENT, position, color));
        } else if (type == "directional") {
            // Vector direction(getVector(Light["direction"]));
            scene.addLight(LightsFactory::createLights(LightType::DIRECTIONAL, position, color));
        } else {
            throw ParserException{"Invalid light type"};
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

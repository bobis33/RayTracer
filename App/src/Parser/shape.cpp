/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** shape
*/

#include "RayTracer/Parser.hpp"
#include "RayTracer/Factory/ShapesFactory.hpp"

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
                // Vector rotation(getVector(shapeSetting["rotation"]));
                scene.addShape(ShapesFactory::createShape(ShapeType::CYLINDER, position, radius));
            } else if (type == "cone") {
                // Vector rotation(getVector(shapeSetting["rotation"]));
                scene.addShape(ShapesFactory::createShape(ShapeType::CONE, position, radius));
            }
        } else {
            throw ParserException{"Invalid shape type"};
        }
    }
}
/*
** EPITECH PROJECT, 2024
** raytracer | parser
** File description:
** shape.cpp
*/

#include "RayTracer/Parser.hpp"
#include "RayTracer/Factory/Shape.hpp"
#include "RayTracer/Factory/Material.hpp"
#include "RayTracer/Composite/Material.hpp"

rtr::ShapeType rtr::Parser::parseShapeType(const std::string &type)
{
    if (type == "plane") {
        return ShapeType::PLANE;
    } if (type == "sphere") {
        return ShapeType::SPHERE;
    } if (type == "cylinder") {
        return ShapeType::CYLINDER;
    } if (type == "cone") {
        return ShapeType::CONE;
    }
    throw ParserException{"Invalid shape type"};
}

std::unique_ptr<rtr::AMaterial> rtr::Parser::parseMaterial(const libconfig::Setting &materialSetting)
{
    std::unique_ptr<CompositeMaterial> composite = std::make_unique<CompositeMaterial>();
    if (!materialSetting.exists("color")) {
        throw ParserException{"Material must have color settings."};
    }
    Color color{convertInt<uint8_t>(materialSetting["color"][0]), convertInt<uint8_t>(materialSetting["color"][1]), convertInt<uint8_t>(materialSetting["color"][2])};
    if (!materialSetting.exists("reflectivity")) {
        throw ParserException{"Material must have reflectivity setting."};
    }
    float reflection = materialSetting["reflectivity"];
    composite->addMaterial(MaterialFactory::createMaterial(MaterialType::REFLECTIVE, reflection));
    if (!materialSetting.exists("transparency")) {
        throw ParserException{"Material must have transparency setting."};
    }
    float transparency = materialSetting["transparency"];
    composite->addMaterial(MaterialFactory::createMaterial(MaterialType::TRANSPARENT, transparency));
    composite->applyMaterial(&color);
    return composite;
}

void rtr::Parser::parseShapes(const libconfig::Setting &shapesSetting, Scene &scene)
{
    for (const auto& shapeSetting : shapesSetting) {
        std::unique_ptr<AShape> shape = nullptr;
        std::unique_ptr<AMaterial> material = std::make_unique<CompositeMaterial>();
        Vector normal;
        Vector rotation;

        if (!shapeSetting.exists("type") || !shapeSetting.exists("position") || !shapeSetting.exists("material")) {
            throw ParserException{"Shape must have a type, position and material setting."};
        }
        ShapeType shapeType(parseShapeType(shapeSetting["type"]));
        Vector position{getVector<Vector>(shapeSetting["position"], convertInt<double>)};
        libconfig::Setting &materialSetting = shapeSetting["material"];
        material = parseMaterial(materialSetting);

        switch (shapeType) {
            case ShapeType::PLANE:
                if (!shapeSetting.exists("normal")) {
                    throw ParserException{"Plane must have a normal setting."};
                }
                normal.setVector(getVector<Vector>(shapeSetting["normal"], convertInt<double>).getValue());
                shape = ShapeFactory::createShape(position, normal);
                break;
            case ShapeType::SPHERE:
                if (!shapeSetting.exists("radius")) {
                    throw ParserException{"Sphere must have a radius setting."};
                }
                shape = ShapeFactory::createShape(position, convertInt<double>(shapeSetting["radius"]));
                break;
            case ShapeType::CYLINDER:
            case ShapeType::CONE: {
                if (!shapeSetting.exists("radius") || !shapeSetting.exists("rotation") || !shapeSetting.exists("height")) {
                    throw ParserException{"Cylinder and Cone must have a radius, a rotation and a height setting."};
                }
                rotation.setVector(getVector<Vector>(shapeSetting["rotation"], convertInt<double>).getValue());
                shape = ShapeFactory::createShape(shapeType, position, rotation, convertInt<double>(shapeSetting["radius"]), convertInt<double>(shapeSetting["height"]));
                break;
            }
            default:
                throw ParserException{"Invalid shape type"};
        }

        if (material != nullptr) {
            shape->setMaterial(std::move(material));
        }
        scene.addShape(std::move(shape));
    }
}
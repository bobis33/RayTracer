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

RayTracer::ShapeType RayTracer::Parser::parseShapeType(const std::string &type)
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

std::unique_ptr<RayTracer::AMaterial> RayTracer::Parser::parseMaterial(const libconfig::Setting &materialSetting)
{
    std::unique_ptr<CompositeMaterial> composite = std::make_unique<CompositeMaterial>();
    if (!materialSetting.exists("color")) {
        throw ParserException{"Material must have color settings."};
    }
    uint8_t r = convertInt<uint8_t>(materialSetting["color"][0]);
    uint8_t g = convertInt<uint8_t>(materialSetting["color"][1]);
    uint8_t b = convertInt<uint8_t>(materialSetting["color"][2]);
    Color color(r, g, b);
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

void RayTracer::Parser::parseShapes(const libconfig::Setting &shapesSetting, Scene &scene)
{
    for (const auto& shapeSetting : shapesSetting) {
        std::unique_ptr<AShape> shape = nullptr;
        std::unique_ptr<AMaterial> material = nullptr;
        if (!shapeSetting.exists("type")) {
            throw ParserException{"Shape must have a type setting."};
        }
        ShapeType shapeType(parseShapeType(shapeSetting["type"]));
        if (!shapeSetting.exists("position")) {
            throw ParserException{"Shape must have a position setting."};
        }
        Vector position(getVector<Vector>(shapeSetting["position"], convertInt<double>));
        double radius = 0;
        if (!shapeSetting.exists("material")) {
            throw ParserException{"Shape must have material setting."};
        }
        libconfig::Setting &materialSetting = shapeSetting["material"];
        material = std::make_unique<CompositeMaterial>();
        material = parseMaterial(materialSetting);

        switch (shapeType) {
            case ShapeType::PLANE:
                shape = ShapeFactory::createShape(position);
                break;
            case ShapeType::SPHERE:
                if (!shapeSetting.exists("radius")) {
                    throw ParserException{"Sphere must have a radius setting."};
                }
                radius = convertInt<double>(shapeSetting["radius"]);
                shape = ShapeFactory::createShape(position, radius);
                break;
            case ShapeType::CYLINDER:
            case ShapeType::CONE: {
                if (!shapeSetting.exists("radius")) {
                    throw ParserException{"Cylinder and Cone must have a radius setting."};
                }
                radius = convertInt<double>(shapeSetting["radius"]);
                if (!shapeSetting.exists("rotation")) {
                    throw ParserException{"Cylinder and Cone must have a rotation setting."};
                }
                Vector rotation = getVector<Vector>(shapeSetting["rotation"], convertInt<double>);
                shape = ShapeFactory::createShape(shapeType,
                                                  position,
                                                  rotation,
                                                  radius);
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
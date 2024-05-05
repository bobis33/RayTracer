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
    throw ParserException{"Invalid material type"};
}

std::unique_ptr<RayTracer::AMaterial> RayTracer::Parser::parseMaterial(const libconfig::Setting &materialSetting)
{
    std::unique_ptr<CompositeMaterial> composite = std::make_unique<CompositeMaterial>();
    Color color(convertInt<uint8_t>(materialSetting["color"][0]), convertInt<uint8_t>(materialSetting["color"][1]), convertInt<uint8_t>(materialSetting["color"][2]));
    if (materialSetting.exists("reflectivity")) {
        float reflection = materialSetting["reflectivity"];
        composite->addMaterial(MaterialFactory::createMaterial(MaterialType::REFLECTIVE, reflection));
    } if (materialSetting.exists("transparency")) {
        float transparency = materialSetting["transparency"];
        composite->addMaterial(MaterialFactory::createMaterial(MaterialType::TRANSPARENT, transparency));
    }

    composite->applyMaterial(&color);
    return composite;
}

void RayTracer::Parser::parseShapes(const libconfig::Setting &shapesSetting, Scene &scene)
{
    for (const auto& shapeSetting : shapesSetting) {
        std::unique_ptr<AShape> shape = nullptr;
        std::unique_ptr<AMaterial> material = nullptr;
        ShapeType shapeType(parseShapeType(shapeSetting["type"]));
        Vector position(getVector<Vector>(shapeSetting["position"], convertInt<int16_t>));
        short radius = 0;

        if (shapeSetting.exists("material")) {
            libconfig::Setting &materialSetting = shapeSetting["material"];
            material = std::make_unique<CompositeMaterial>();
            material = parseMaterial(materialSetting);
        }

        switch (shapeType) {
            case ShapeType::PLANE:
                shape = ShapeFactory::createShape(position);
                break;
            case ShapeType::SPHERE:
                radius = convertInt<int16_t>(shapeSetting["radius"]);
                shape = ShapeFactory::createShape(position, radius);
                break;
            case ShapeType::CYLINDER:
            case ShapeType::CONE: {
                radius = convertInt<int16_t>(shapeSetting["radius"]);
                shape = ShapeFactory::createShape(shapeType,
                                                  position,
                                                  Vector(getVector<Vector>(shapeSetting["rotation"], convertInt<int16_t>)),
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
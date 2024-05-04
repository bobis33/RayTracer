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
    for (int i = 0; i < shapesSetting.getLength(); i++) {
        const libconfig::Setting &shapeSetting = shapesSetting[i];
        std::string type = shapeSetting["type"];
        Vector position(getVector(shapeSetting["position"]));
        std::unique_ptr<AShape> shape = nullptr;
        std::unique_ptr<AMaterial> material = nullptr;

        if (shapeSetting.exists("material")) {
            libconfig::Setting &materialSetting = shapeSetting["material"];
            material = std::make_unique<CompositeMaterial>();
            material = parseMaterial(materialSetting);
        }
        if (type == "plane") {
            shape = ShapeFactory::createShape(ShapeType::PLANE, position);
        } else if (type == "sphere" || type == "cylinder" || type == "cone") {
            libconfig::Setting &radiusSetting = shapeSetting["radius"];
            auto radius = convertInt<int16_t>(radiusSetting);
            if (type == "sphere") {
                shape = ShapeFactory::createShape(ShapeType::SPHERE, position, radius);
            } else if (type == "cylinder") {
                // Vector rotation(getVector(shapeSetting["rotation"]));
                shape = ShapeFactory::createShape(ShapeType::CYLINDER, position, radius);
            } else if (type == "cone") {
                // Vector rotation(getVector(shapeSetting["rotation"]));
                shape = ShapeFactory::createShape(ShapeType::CONE, position, radius);
            }
        } else {
            throw ParserException{"Invalid shape type"};
        }

        if (material != nullptr) {
            shape->setMaterial(std::move(material));
        }
        scene.addShape(std::move(shape));
    }
}
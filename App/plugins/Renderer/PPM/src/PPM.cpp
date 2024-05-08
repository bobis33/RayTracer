/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <iostream>
#include <fstream>

#include "RayTracer/PPM.hpp"

void RayTracer::PPM::writePixels(const std::unique_ptr<AShape> &shape, const Camera &camera, unsigned short x, unsigned short y)
{
    switch (shape->getType()) {
        case ShapeType::PLANE:
            if (shape->hits(camera.ray(static_cast<double>(x) / getResolution().getWidth(),
                                       static_cast<double>(y) / getResolution().getHeight()))) {
                getPixels()[y][x].setColor(shape->getMaterial().getColor().getValue());
            } else {
                getPixels()[y][x].setColor(getBackgroundColor().getValue());
            }
        case ShapeType::SPHERE:
            if (shape->hits(camera.ray(static_cast<double>(x) / getResolution().getWidth(),
                                       static_cast<double>(y) / getResolution().getHeight()))) {
                getPixels()[y][x].setColor(shape->getMaterial().getColor().getValue());
            }
            break;

        case ShapeType::CONE:
            break;

        case ShapeType::CYLINDER:
            break;

        default:
            break;
        }

}

void RayTracer::PPM::render(const std::vector<std::unique_ptr<AShape>> &shapes, Camera &camera)
{
    setPixels({getResolution().getHeight(), std::vector<RayTracer::Color>(getResolution().getWidth())});

    Vector cone_pos = {0, 0, 0};
    Vector cone_rot = {0, 0, 0};

    for(unsigned short y = 0; y < getResolution().getHeight(); y++) {
        for (unsigned short x = 0; x < getResolution().getWidth(); x++) {
            for(const auto &shape : shapes) {
                if (shape->getType() == ShapeType::CONE) {
                    cone_pos = shape->getPosition();
                    cone_rot = shape->getRotation();
                }
                writePixels(shape, camera, x, y);
            }
        }
    }
    std::cout << "Cone :" << std::endl;
    std::cout << "Position : " << cone_pos.getValue().x << " " << cone_pos.getValue().y << " " << cone_pos.getValue().z << std::endl;
    std::cout << "Rotation : " << cone_rot.getValue().x << " " << cone_rot.getValue().y << " " << cone_rot.getValue().z << std::endl;

    std::ofstream file(getName() + ".ppm");
    if (file.is_open()) {
        file << "P6\n" << getResolution().getWidth() << " " << getResolution().getHeight() << "\n255\n";

        for (const auto& row : getPixels()) {
            file.write(reinterpret_cast<const char*>(row.data()), static_cast<long>(row.size() * sizeof(Color)));
        }
        file.close();
    }

    std::string command = "open " + getName() + ".ppm";
    system(command.c_str());
    return;
}

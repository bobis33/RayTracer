/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <iostream>
#include <fstream>

#include "RayTracer/PPM.hpp"

void RayTracer::PPM::render(const std::vector<std::unique_ptr<AShape>> &shapes, const Camera &camera)
{
    uint16_t width = getResolution().getWidth();
    uint16_t height = getResolution().getHeight();

    Vector cameraOrigin(camera.getOrigin());
    Vector cameraDirection(camera.getDirection());
    int16_t aspectRatio = static_cast<int16_t>(width / height);
    Rectangle3D cameraScreen(RayTracer::Vector(-aspectRatio, -1, 0), RayTracer::Vector(2 * aspectRatio, 0, 0), RayTracer::Vector(0, 2, 0));

    Cameraa cam(cameraOrigin, cameraScreen, cameraDirection);

    Color backgroundColor(this->getBackgroundColor().getValue());
    std::vector<std::vector<RayTracer::Color>> pixels(height, std::vector<RayTracer::Color>(width));
    for (unsigned long y = 0; y < height; y++) {
        for (unsigned long x = 0; x < width; x++) {
            pixels[y][x] = backgroundColor;
        }
    }
    setPixels(pixels);

    for(const auto &shape : shapes) {
        Vector position(shape->getPosition());
        //std::cout << +a.getX() << " " << +a.getY() << " " << +a.getZ() << std::endl;
        switch (shape->getType()) {
            case ShapeType::SPHERE:
                Color(shape->getMaterial().getColor());
                break;
            default:
                break;
        }
    }

    //RayTracer::Sphere s(point3D, radius);

    //std::vector<std::vector<RayTracer::Color> > pixels(height, std::vector<RayTracer::Color>(width));

    /* for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double u = static_cast<double>(x) / width;
            double v = static_cast<double>(y) / height;

            RayTracer::Ray r = cam.ray(u, v);

            if (s.hits(r)) {
                pixels[y][x] = RayTracer::Color(255, 0, 0);
            } else {
                pixels[y][x] = RayTracer::Color(0, 0, 0);
            }
        }
    } */

    std::ofstream file(getName() + ".ppm");
    if (file.is_open()) {
        file << "P6\n" << width << " " << height << "\n255\n";

        for (unsigned long y = 0; y < height; y++) {
            for (unsigned long x = 0; x < width; x++) {
                file << static_cast<char>(getPixels()[y][x].getValue().r) << static_cast<char>(getPixels()[y][x].getValue().g) << static_cast<char>(getPixels()[y][x].getValue().b);
            }
        }
        file.close();

    }

    std::string command = "open " + getName() + ".ppm";
    system(command.c_str());
    return;

}

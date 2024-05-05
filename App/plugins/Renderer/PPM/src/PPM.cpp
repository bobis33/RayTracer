/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** PPM.cpp
*/

#include <iostream>
#include <fstream>

#include "RayTracer/PPM.hpp"

void RayTracer::PPM::render(const std::vector<std::unique_ptr<AShape>> &shapes)
{
    RayTracer::Point3D point3D(0, 0, 0);
    double radius = 0;
    for(const auto &shape : shapes) {
        auto a = shape->getPosition();
        //std::cout << +a.getX() << " " << +a.getY() << " " << +a.getZ() << std::endl;
        if (shape->getType() == RayTracer::ShapeType::SPHERE) {
            point3D.x = a.getX();
            point3D.y = a.getY();
            point3D.z = a.getZ();
            radius = shape->getRadius();
        }
    }

    unsigned long width = getResolution().getWidth();
    unsigned long height = getResolution().getHeight();

    RayTracer::Sphere s(point3D, radius);

    RayTracer::Point3D cameraOrigin(0, 0, 0);
    RayTracer::Vector3D cameraDirection(0, 0, -1);
    double aspectRatio = static_cast<double>(width) / static_cast<double>(height);
    RayTracer::Rectangle3D cameraScreen(RayTracer::Point3D(-aspectRatio, -1, 0), RayTracer::Vector3D(2 * aspectRatio, 0, 0), RayTracer::Vector3D(0, 2, 0));

    RayTracer::Cameraa cam(cameraOrigin, cameraScreen, cameraDirection);

    std::vector<std::vector<RayTracer::Color> > pixels(height, std::vector<RayTracer::Color>(width));

    for (unsigned long y = 0; y < height; y++) {
        for (unsigned long x = 0; x < width; x++) {
            double u = static_cast<double>(x) / static_cast<double>(width);
            double v = static_cast<double>(y) / static_cast<double>(height);

            RayTracer::Ray r = cam.ray(u, v);

            if (s.hits(r)) {
                pixels[y][x] = RayTracer::Color(255, 0, 0);
            } else {
                pixels[y][x] = RayTracer::Color(0, 0, 0);
            }
        }
    }

    std::ofstream file(getName() + ".ppm");
    if (file.is_open()) {
        file << "P6\n" << width << " " << height << "\n255\n";

        for (unsigned long y = 0; y < height; y++) {
            for (unsigned long x = 0; x < width; x++) {
                file << static_cast<char>(pixels[y][x].getValue().r) << static_cast<char>(pixels[y][x].getValue().g) << static_cast<char>(pixels[y][x].getValue().b);
            }
        }
        file.close();
    }
}

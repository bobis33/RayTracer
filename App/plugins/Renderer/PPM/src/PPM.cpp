/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** PPM.cpp
*/

#include <iostream>
#include <fstream>

#include "RayTracer/PPM.hpp"
#include "RayTracer/Scene/Scene.hpp"

void RayTracer::PPM::render(const std::vector<std::unique_ptr<AShape>> &shapes)
{
    for(auto &shape : shapes) {
        auto a = shape->getPosition();
        // std::cout << +a.getX() << " " << +a.getY() << " " << +a.getZ() << std::endl;
    }

    std::ofstream file(getName() + ".ppm");

    file << "P3\n" << getResolution().getWidth() << " " << getResolution().getHeight() << "\n255\n";

    std::string colorString = "255 30 140 ";

    for (int i = 0; i < getResolution().getHeight(); i++) {
        for (int j = 0; j < getResolution().getWidth(); j++) {
            file << colorString;
        }
        file << "\n";
    }

    file.close();
}

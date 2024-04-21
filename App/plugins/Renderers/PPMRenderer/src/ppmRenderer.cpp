/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <iostream>
#include <fstream>

#include "RayTracer/PpmRenderer.hpp"

void RayTracer::PpmRenderer::render()
{
    std::ofstream file(getName() + ".ppm");

    file << "P3\n" << getResolution().getWidth() << " " << getResolution().getHeight() << "\n255\n";

    for (int i = 0; i < getResolution().getHeight(); i++) {
        for (int j = 0; j < getResolution().getWidth(); j++) {
            file << "0 0 0 ";
        }
        file << "\n";
    }

    file.close();
}

/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <iostream>
#include <fstream>

#include "RayTracer/PpmRenderer.hpp"

void RayTracer::PpmRenderer::render(const Scene &scene)
{
    setName(scene.getName());
    setResolution(scene.getResolution());

    std::ofstream file(getName() + ".ppm");

    file << "P3\n" << getResolution().first << " " << getResolution().second << "\n255\n";

    for (int i = 0; i < getResolution().second; i++) {
        for (int j = 0; j < getResolution().first; j++) {
            file << "0 0 0 ";
        }
        file << "\n";
    }

    file.close();
}

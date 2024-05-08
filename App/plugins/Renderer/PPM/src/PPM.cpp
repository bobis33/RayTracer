/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <fstream>
#include <filesystem>

#include "RayTracer/PPM.hpp"

void RayTracer::PPM::writeToFile(const std::string &width, const std::string &height)
{
    const std::string header = getHeader(width, height);
    std::filesystem::path filePath(getName());
    filePath.replace_extension(".ppm");
    std::ofstream file(filePath);
    if (file.is_open()) {
        file.write(header.data(),
                   static_cast<long>(header.size() * sizeof(char)));

        for (const auto& row : getPixels()) {
            file.write(reinterpret_cast<const char*>(row.data()), static_cast<long>(row.size() * sizeof(Color)));
        }
        file.close();
    }
}

void RayTracer::PPM::writePixels(bool hit, const color_t &color, std::size_t width, std::size_t height)
{
    if (hit) {
        getPixels()[height][width].setColor(color);
    }
}

void RayTracer::PPM::render(const std::vector<AShape*> &shapes, const Camera &camera)
{
    const auto& width = getResolution().getWidth();
    const auto& height = getResolution().getHeight();
    setPixels({height, std::vector<RayTracer::Color>(width)});

    for (auto &row : getPixels()) {
        for (auto &pixel : row) {
            pixel.setColor(getBackgroundColor().getValue());
        }
    }

    for(std::size_t index_height = 0; index_height < height; index_height++) {
        for (unsigned short index_width = 0; index_width < width; index_width++) {
            for(const auto &shape : shapes) {
                writePixels(shape->hits(camera.ray(static_cast<double>(index_width) / width, static_cast<double>(index_height) / height)),
                            shape->getMaterial().getColor().getValue(),
                            index_width,
                            index_height);
            }
        }
    }

    writeToFile(std::to_string(width), std::to_string(height));

    // to remove
    std::string command = "open " + getName() + ".ppm";
    system(command.c_str());
    return;
}

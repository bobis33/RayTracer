/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <fstream>
#include <filesystem>

#include "RayTracer/PPM.hpp"

void rtr::PPM::writeToFile(const std::string &width, const std::string &height)
{
    const std::string header = getHeader(width, height);
    std::filesystem::path filePath(getName());
    filePath.replace_extension(".ppm");
    std::ofstream file(filePath);
    if (file.is_open()) {
        file.write(header.data(),
                   static_cast<long>(header.size() * sizeof(char)));

        for (std::vector<Color> const &row : getPixels()) {
            file.write(reinterpret_cast<const char*>(row.data()), static_cast<long>(row.size() * sizeof(Color)));
        }
        file.close();
    }
}

void rtr::PPM::render(const std::vector<std::unique_ptr<AShape>> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const Camera &camera)
{
    const uint16_t& width = getResolution().getWidth();
    const uint16_t& height = getResolution().getHeight();
    setPixels({height, std::vector<rtr::Color>(width)});

    for (std::vector<rtr::Color> &row : getPixels()) {
        for (rtr::Color &pixel : row) {
            pixel.setColor(getBackgroundColor().getValue());
        }
    }

    for(std::size_t index_height = 0; index_height < height; index_height++) {
        for (unsigned short index_width = 0; index_width < width; index_width++) {
            RayHit hit;
            for(const std::unique_ptr<AShape> &shape : shapes) {
                if (shape->hits(camera.ray(static_cast<double>(index_width) / width,
                                           static_cast<double>(index_height) / height),
                                hit)) {
                    Color color = shape->getMaterial().getColor();
                    for (const std::unique_ptr<ALight> &light : lights) {
                        if (light->getType() == LightType::DIRECTIONAL) {
                            color += light->LightColor(hit.getRayHit().normal.normalize(), hit.getRayHit().point , color, shapes);
                        }
                    }
                    writePixels(true, color.getValue(), index_width, index_height);
                }
            }
        }
    }

    writeToFile(std::to_string(width), std::to_string(height));

    // to remove
    std::string command = "open " + getName() + ".ppm";
    system(command.c_str());
    return;
}

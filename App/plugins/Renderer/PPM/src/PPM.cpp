/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <fstream>
#include <filesystem>

#include "RayTracer/PPM.hpp"

bool rtr::PPM::isShadowed(const Vector &lightDir, const Vector &point, const std::vector<std::unique_ptr<AShape>> &shapes)
{
    RayHit hit;
    for (const std::unique_ptr<AShape> &shape : shapes) {
        if (shape->hits({point, lightDir}, hit)) {
            return true;
        }
    }
    return false;
}

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
    const uint16_t width = getResolution().getWidth();
    const uint16_t height = getResolution().getHeight();
    RayHit hit;
    Color finalColor;

    setPixels({height, std::vector<rtr::Color>(width)});

    for (std::vector<rtr::Color> &row : getPixels()) {
        for (rtr::Color &pixel : row) {
            pixel.setColor(getBackgroundColor().getValue());
        }
    }

    for(std::size_t index_height = 0; index_height < height; index_height++) {
        for (std::size_t index_width = 0; index_width < width; index_width++) {
            for(const std::unique_ptr<AShape> &shape : shapes) {
                if (shape->hits(camera.ray(static_cast<double>(index_width) / width,
                                           static_cast<double>(index_height) / height),
                                hit)) {
                    finalColor = shape->getMaterial().getColor();
                    for (const std::unique_ptr<ALight> &light : lights) {
                        if (light->getType() == LightType::DIRECTIONAL && !isShadowed(light->getDirection(), hit.getRayHit().point, shapes)) {
                            finalColor += light->LightColor(hit.getRayHit().point.normalize(),
                                                            finalColor);
                        } else if (light->getType() == LightType::AMBIENT) {
                            finalColor += light->LightColor(hit.getRayHit().point.normalize(), finalColor);
                        }
                    }
                    writePixels(finalColor, index_width, index_height);
                }
            }
        }
    }

    writeToFile(std::to_string(width), std::to_string(height));
}

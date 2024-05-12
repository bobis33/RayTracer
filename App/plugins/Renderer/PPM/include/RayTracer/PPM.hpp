/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** PPM.hpp
*/

#ifndef RAYTRACER_PPM_RENDERER_HPP
#define RAYTRACER_PPM_RENDERER_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Scene/Camera.hpp"
#include "RayTracer/Scene/Scene.hpp"

namespace rtr {

    class PPM : public ARenderer {

        public:
            ~PPM() override = default;

            [[nodiscard]] std::string getPluginName() const override { return PPM_RENDERER; };

            void render(const std::vector<std::unique_ptr<AShape>> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const Camera &camera) override;

            [[nodiscard]] static std::string getHeader(const std::string &width, const std::string &height) { return "P6\n" + width + " " + height + "\n255\n"; };

            void writePixels(bool hit, const color_t &color, std::size_t width, std::size_t height) { if (hit) { getPixels()[height][width].setColor(color); } };
            void writeToFile(const std::string &width, const std::string &height);

        rtr::Color getColor(double u, double v, const Camera &camera, const std::vector<std::unique_ptr<AShape>> &shapes, const std::vector<std::unique_ptr<ALight>> &lights)
        {
            return getColor(camera.ray(u, v), shapes, lights);
        }

        static rtr::Color getColor(std::pair<Vector, Vector> ray, const std::vector<std::unique_ptr<AShape>> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const std::unique_ptr<AShape> &lastShape = nullptr)
        {
            RayHit closestHit;
            double closestDistance = std::numeric_limits<double>::max();
            AShape *closestShape = nullptr;

            for (const auto &shape : shapes) {
                RayHit hit;
                if (shape->hits(ray, hit) && hit.getRayHit().distance < closestDistance) {
                    closestHit = hit;
                    closestDistance = hit.getRayHit().distance;
                    closestShape = shape.get();
                }
            }

            if (closestShape == nullptr) {
                return {0, 0, 0};
            }

            rtr::Color color = closestShape->getMaterial().getColor();

            for (const auto &light : lights) {
                Vector lightDir = light->getPosition() - closestHit.getRayHit().point;
                lightDir = lightDir.normalize();
                double lightIntensity = std::max(0.0, lightDir.dot(closestHit.getRayHit().normal));
                color += light->getColor() * lightIntensity;
            }

            return color;
        }

    }; // class PPM

} // namespace RayTracer

#endif // RAYTRACER_PPM_RENDERER_HPP

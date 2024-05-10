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

namespace rtr {

    class PPM : public ARenderer {

        public:
            ~PPM() override = default;

            [[nodiscard]] std::string getPluginName() const override { return PPM_RENDERER; };

            void render(const std::vector<AShape*> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const Camera &camera) override;

            [[nodiscard]] static std::string getHeader(const std::string &width, const std::string &height) { return "P6\n" + width + " " + height + "\n255\n"; };

            void writePixels(bool hit, const color_t &color, std::size_t width, std::size_t height) { if (hit) { getPixels()[height][width].setColor(color); } };
            void writeToFile(const std::string &width, const std::string &height);

    }; // class PPM

} // namespace RayTracer

#endif // RAYTRACER_PPM_RENDERER_HPP

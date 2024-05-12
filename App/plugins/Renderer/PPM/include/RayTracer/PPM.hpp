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

            [[nodiscard]] static std::string getHeader(const std::string &width, const std::string &height) { return "P6\n" + width + ' ' + height + "\n255\n"; };

            void render(const std::vector<std::unique_ptr<AShape>> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const Camera &camera) override;

            void writePixels(const Color color, const std::size_t width, const std::size_t height) { getPixels()[height][width].setColor(color.getValue()); };
            void writeToFile(const std::string &width, const std::string &height);
            bool isShadowed(const Vector &lightDir, const Vector &point, const std::vector<std::unique_ptr<AShape>> &shapes);

    }; // class PPM

} // namespace RayTracer

#endif // RAYTRACER_PPM_RENDERER_HPP

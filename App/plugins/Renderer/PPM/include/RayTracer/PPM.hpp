/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** PPM.hpp
*/

#ifndef RAYTRACER_PPM_RENDERER_HPP
#define RAYTRACER_PPM_RENDERER_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Scene/Camera.hpp"

namespace RayTracer {

    class PPM : public ARenderer {

        public:
            ~PPM() override = default;

            [[nodiscard]] std::string getPluginName() const override { return PPM_RENDERER; };

            void render(const std::vector<AShape*> &shapes, const Camera &camera) override;

            [[nodiscard]] static std::string getHeader(const std::string &width, const std::string &height) { return "P6\n" + width + " " + height + "\n255\n"; };

            void writePixels(bool hit, const color_t &color, std::size_t width, std::size_t height);
            void writeToFile(const std::string &width, const std::string &height);

    }; // class PPM

} // namespace RayTracer

#endif // RAYTRACER_PPM_RENDERER_HPP

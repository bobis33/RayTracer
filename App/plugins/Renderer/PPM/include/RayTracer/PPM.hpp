/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** PPM.hpp
*/

#ifndef RAYTRACER_PPM_RENDERER_HPP
#define RAYTRACER_PPM_RENDERER_HPP

#include <vector>

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Scene/Camera.hpp"

namespace RayTracer {

    class PPM : public ARenderer {

        public:
            ~PPM() override = default;

            [[nodiscard]] std::string getPluginName() const override { return PPM_RENDERER; };

            void render(const std::vector<std::unique_ptr<AShape>>& shapes, const Camera &camera) override;

    }; // class PPM

} // namespace RayTracer

#endif // RAYTRACER_PPM_RENDERER_HPP

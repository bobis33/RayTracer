/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** SFML.hpp
*/

#ifndef RAYTRACER_SFML_RENDERER_HPP
#define RAYTRACER_SFML_RENDERER_HPP

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Scene/Camera.hpp"

namespace rtr {

    class SFML : public ARenderer {

        public:
            SFML() = default;
            ~SFML() override = default;

            [[nodiscard]] std::string getPluginName() const override { return SFML_RENDERER; };

            void render(const std::vector<std::unique_ptr<AShape>> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const Camera &camera) override;

    }; // class SFML

} // namespace RayTracer

#endif // RAYTRACER_SFML_RENDERER_HPP

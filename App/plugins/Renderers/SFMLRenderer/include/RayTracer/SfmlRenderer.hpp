/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** SfmlRenderer.hpp
*/

#ifndef RAYTRACER_SFML_RENDERER_HPP
#define RAYTRACER_SFML_RENDERER_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"

namespace RayTracer {

    class SfmlRenderer : public ARenderer {

        public:
            SfmlRenderer() = default;
            ~SfmlRenderer() override = default;

            [[nodiscard]] std::string getPluginName() const override { return SFML_RENDERER; };

            void render() override;

    }; // class SfmlRenderer

} // namespace RayTracer

#endif // RAYTRACER_SFML_RENDERER_HPP

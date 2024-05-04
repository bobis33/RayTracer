/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** SFML.hpp
*/

#ifndef RAYTRACER_SFML_RENDERER_HPP
#define RAYTRACER_SFML_RENDERER_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"

namespace RayTracer {

    class SFML : public ARenderer {

        public:
            SFML() = default;
            ~SFML() override = default;

            [[nodiscard]] std::string getPluginName() const override { return SFML_RENDERER; };

            void render() override;

    }; // class SFML

} // namespace RayTracer

#endif // RAYTRACER_SFML_RENDERER_HPP

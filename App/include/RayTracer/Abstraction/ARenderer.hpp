/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ARenderer.cpp
*/

#ifndef RAYTRACER_ARENDERER_HPP
#define RAYTRACER_ARENDERER_HPP

#include "RayTracer/Abstraction/IRenderer.hpp"

namespace RayTracer {

    class ARenderer : public IRenderer {

        public:
            ~ARenderer() override = default;

            void setType(const RendererType &rendererType) override { m_type = rendererType; };
            void setName(const std::string &name) override { m_name = name; };

            [[nodiscard]] RendererType getType() const override { return m_type; };
            [[nodiscard]] Resolution getResolution() const override { return m_resolution; };
            [[nodiscard]] std::string getName() const override { return m_name; };

        private:
            RendererType m_type{RendererType::NONE};
            Resolution m_resolution{{1920, 1080}};
            std::string m_name{"Default Renderer Name"};

    }; // class ARenderer

} // namespace RayTracer

#endif //RAYTRACER_ARENDERER_HPP

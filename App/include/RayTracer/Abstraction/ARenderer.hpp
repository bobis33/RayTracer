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
            void setResolution(const Resolution_t &resolution) override { m_resolution = resolution; };
            void setName(const std::string &name) override { m_name = name; };

            [[nodiscard]] RendererType getType() const override { return m_type; };
            [[nodiscard]] Resolution_t getResolution() const override { return m_resolution; };
            [[nodiscard]] std::string getName() const override { return m_name; };

        private:
            RendererType m_type{RendererType::NONE};
            Resolution_t m_resolution{DEFAULT_WIDTH, DEFAULT_HEIGHT};
            std::string m_name{"Default Renderer Name"};

    }; // class ARenderer

} // namespace RayTracer

#endif //RAYTRACER_ARENDERER_HPP

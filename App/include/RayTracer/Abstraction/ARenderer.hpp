/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ARenderer.cpp
*/

#ifndef RAYTRACER_ARENDERER_HPP
#define RAYTRACER_ARENDERER_HPP

#include "RayTracer/Abstraction/IRenderer.hpp"

namespace rtr {

    class ARenderer : public IRenderer {

        public:

            ~ARenderer() override = default;

            void setType(const RendererType &rendererType) override { m_type = rendererType; };
            void setName(const std::string &name) override { m_name = name; };

            [[nodiscard]] const RendererType& getType() const override { return m_type; };
            [[nodiscard]] Resolution& getResolution() override { return m_resolution; };
            [[nodiscard]] Color& getBackgroundColor() override { return m_backgroundColor; };
            [[nodiscard]] const std::string& getName() const override { return m_name; };
            [[nodiscard]] std::vector<std::vector<rtr::Color>>& getPixels() override { return m_pixels; };
            void setPixels(const std::vector<std::vector<rtr::Color>>& pixels) override { m_pixels = pixels; };

        private:

            RendererType m_type{RendererType::NONE};
            Resolution m_resolution{1920, 1080};
            std::string m_name{"Default Renderer Name"};
            Color m_backgroundColor{Color::getBlack()};
            std::vector<std::vector<rtr::Color>> m_pixels;

    }; // class ARenderer

} // namespace RayTracer

#endif //RAYTRACER_ARENDERER_HPP

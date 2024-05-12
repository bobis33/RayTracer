/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ARenderer.cpp
*/

/// @file ARenderer.hpp
#ifndef RAYTRACER_ARENDERER_HPP
#define RAYTRACER_ARENDERER_HPP

#include "RayTracer/Abstraction/IRenderer.hpp"

namespace rtr {

    /// @class ARenderer
    /// @brief An abstract class for renderers, based on the interface IRenderer.
    class ARenderer : public IRenderer {

        public:

            ~ARenderer() override = default;

            void setType(const RendererType &rendererType) override { m_type = rendererType; };
            void setName(const std::string &name) override { m_name = name; };
            void setPixels(const std::vector<std::vector<rtr::Color>>& pixels) override { m_pixels = pixels; };

            [[nodiscard]] const RendererType& getType() const override { return m_type; };
            [[nodiscard]] Resolution& getResolution() override { return m_resolution; };
            [[nodiscard]] Color& getBackgroundColor() override { return m_backgroundColor; };
            [[nodiscard]] const std::string& getName() const override { return m_name; };
            [[nodiscard]] std::vector<std::vector<rtr::Color>>& getPixels() override { return m_pixels; };


        private:

            /// @brief The type of the renderer.
            RendererType m_type{RendererType::NONE};

            /// @brief The resolution of the renderer.
            Resolution m_resolution{1920, 1080};

            /// @brief The name of the renderer.
            std::string m_name{"Default Renderer Name"};

            /// @brief The background color of the renderer.
            Color m_backgroundColor{Color::getBlack()};

            /// @brief The pixels of the renderer.
            std::vector<std::vector<rtr::Color>> m_pixels;

    }; // class ARenderer

} // namespace RayTracer

#endif //RAYTRACER_ARENDERER_HPP

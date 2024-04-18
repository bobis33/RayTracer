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

    enum class RendererType {
        PPM,
        SFML,
        NONE
    };

    class ARenderer : public IRenderer {

        public:
            ~ARenderer() override = default;

            void setResolution(const std::pair<uint16_t, uint16_t> &resolution) { m_resolution = resolution; }
            void setName(const std::string &name) { m_name = name; }
            void setType(const RendererType &type) { m_type = type; }

            [[nodiscard]] std::pair<uint16_t, uint16_t> getResolution() const { return m_resolution; }
            [[nodiscard]] std::string getName() const { return m_name; }
            [[nodiscard]] RendererType getType() const { return m_type; }

        private:
            std::pair<uint16_t, uint16_t> m_resolution{1920, 1080};
            std::string m_name{"RayTracer"};
            RendererType m_type{RendererType::NONE};

    }; // class ARenderer

} // namespace RayTracer

#endif //RAYTRACER_ARENDERER_HPP

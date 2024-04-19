/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IRenderer.cpp
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

#include "RayTracer/Scene/Scene.hpp"

namespace RayTracer {

    enum class RendererType : uint8_t {
        PPM,
        SFML,
        NONE
    };

    class IRenderer {

        public:
            virtual ~IRenderer() = default;

            virtual void render(const Scene &scene) = 0;

            virtual void setResolution(const std::pair<uint16_t, uint16_t> &resolution) = 0;
            virtual void setName(const std::string &name) = 0;
            virtual void setType(const RendererType &type) = 0;

            [[nodiscard]] virtual std::pair<uint16_t, uint16_t> getResolution() const = 0;
            [[nodiscard]] virtual std::string getName() const = 0;
            [[nodiscard]] virtual RendererType getType() const = 0;


    }; // IRenderer

} // namespace RayTracer

#endif //RAYTRACER_IRENDERER_HPP

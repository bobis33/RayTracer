/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IRenderer.cpp
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

#include <cstdint>

#include "RayTracer/Constants.hpp"

namespace RayTracer {

    using Resolution_t = struct Resolution_s {
        uint16_t width;
        uint16_t height;
    };

    class IRenderer {

        public:
            virtual ~IRenderer() = default;

            virtual void render() = 0;

            virtual void setType(const RendererType &rendererType) = 0;
            virtual void setResolution(const Resolution_t &resolution) = 0;
            virtual void setName(const std::string &name) = 0;

            [[nodiscard]] virtual RendererType getType() const = 0;
            [[nodiscard]] virtual Resolution_t getResolution() const = 0;
            [[nodiscard]] virtual std::string getName() const = 0;

    }; // IRenderer

} // namespace RayTracer

#endif //RAYTRACER_IRENDERER_HPP

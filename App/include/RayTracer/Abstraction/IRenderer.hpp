/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IRenderer.cpp
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

#include <cstdint>

#include "RayTracer/Resolution.hpp"
#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class IRenderer {

        public:
            virtual ~IRenderer() = default;

            virtual void render() = 0;

            virtual void setType(const RendererType &rendererType) = 0;
            virtual void setName(const std::string &name) = 0;

            [[nodiscard]] virtual RendererType getType() const = 0;
            [[nodiscard]] virtual Resolution getResolution() const = 0;
            [[nodiscard]] virtual std::string getName() const = 0;

    }; // IRenderer

} // namespace RayTracer

#endif //RAYTRACER_IRENDERER_HPP

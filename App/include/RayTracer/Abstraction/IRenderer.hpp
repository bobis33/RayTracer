/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IRenderer.cpp
*/

#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

#include <cstdint>

#include "RayTracer/Abstraction/IPlugin.hpp"
#include "RayTracer/Utils/Resolution.hpp"
#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class IRenderer : public IPlugin {

        public:

            virtual void render() = 0;

            virtual void setType(const RendererType &rendererType) = 0;
            virtual void setName(const std::string &name) = 0;

            [[nodiscard]] virtual const RendererType& getType() const = 0;
            [[nodiscard]] virtual const std::string& getName() const = 0;
            [[nodiscard]] virtual Resolution& getResolution() = 0;

    }; // IRenderer

} // namespace RayTracer

#endif //RAYTRACER_IRENDERER_HPP

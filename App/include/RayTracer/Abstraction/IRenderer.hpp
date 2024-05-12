/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IRenderer.cpp
*/

/// @file IRenderer.hpp
#ifndef RAYTRACER_IRENDERER_HPP
#define RAYTRACER_IRENDERER_HPP

#include <vector>

#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Scene/Camera.hpp"
#include "RayTracer/Utils/Resolution.hpp"
#include "RayTracer/Constants.hpp"

namespace rtr {

    /// @class IRenderer
    /// @brief An interface for renderers.
    class IRenderer : public IPlugin {

        public:

            /// @brief Renders the scene based on the shapes, lights and camera.
            /// @param shapes The shapes of the scene.
            /// @param lights The lights of the scene.
            /// @param camera The camera of the scene.
            virtual void render(const std::vector<std::unique_ptr<AShape>> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const Camera &camera) = 0;

            /// @brief Sets the type of the renderer.
            /// @param rendererType The type of the renderer (defined in the RendererType enum class).
            virtual void setType(const RendererType &rendererType) = 0;

            /// @brief Sets the name of the renderer.
            /// @param name The name of the renderer, based on the configuration file.
            virtual void setName(const std::string &name) = 0;

            /// @brief Sets the pixels of the renderer.
            /// @param pixels The pixels of the renderer.
            virtual void setPixels(const std::vector<std::vector<rtr::Color>>& pixels) = 0;

            /// @brief Gets the type of the renderer based on the configuration file.
            /// @return The type of the renderer, using the enum class RendererType.
            [[nodiscard]] virtual const RendererType& getType() const = 0;

            /// @brief Gets the name of the renderer based on the configuration file.
            /// @return A string of the renderer's name.
            [[nodiscard]] virtual const std::string& getName() const = 0;

            /// @brief Gets the resolution of the renderer based on the configuration file.
            /// @return The resolution of the renderer using the Resolution class.
            [[nodiscard]] virtual Resolution& getResolution() = 0;

            /// @brief Gets the background color of the renderer based on the configuration file.
            /// @return The background color of the renderer.
            [[nodiscard]] virtual Color& getBackgroundColor() = 0;

            /// @brief Gets the pixels of the renderer based on the configuration file.
            /// @return Each pixels of the image.
            [[nodiscard]] virtual std::vector<std::vector<rtr::Color>>& getPixels() = 0;

    }; // IRenderer

} // namespace RayTracer

#endif //RAYTRACER_IRENDERER_HPP

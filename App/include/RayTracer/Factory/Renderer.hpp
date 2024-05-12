/*
** EPITECH PROJECT, 2024
** Raytracer | Factory
** File description:
** Renderer.hpp
*/

/// @file Renderer.hpp
#ifndef RAYTRACER_RENDERER_FACTORY_HPP
#define RAYTRACER_RENDERER_FACTORY_HPP

#include "RayTracer/Abstraction/ARenderer.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace rtr {

    /// @class RendererFactory
    /// @brief A factory class to create the renderers.
    class RendererFactory {

        public:
            /// @brief Creates a renderer based on the type, name, resolution and background color.
            /// @param type The type of the renderer (defined in the RendererType enum class).
            /// @param name A string of the renderer's name.
            /// @param resolution The resolution of the renderer.
            /// @param backgroundColor The background color of the renderer.
            /// @return A unique pointer to the renderer.
            static std::unique_ptr<ARenderer> createRenderer(const RendererType &type,
                                                             const std::string &name,
                                                             const Resolution &resolution,
                                                             const Color &backgroundColor);

    }; // class RendererFactory

} // namespace RayTracer

#endif //RAYTRACER_RENDERER_FACTORY_HPP

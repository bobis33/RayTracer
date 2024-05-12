/*
** EPITECH PROJECT, 2024
** Raytracer | Scene
** File description:
** Scene.hpp
*/

/// @file Scene.hpp
#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include <vector>

#include "RayTracer/Scene/Camera.hpp"
#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Factory/Renderer.hpp"

namespace rtr {

    /// @class Scene
    /// @brief A class to represent the scene.
    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            /// @brief Sets the camera of the scene.
            /// @param camera The camera to set.
            void setCamera(const Camera &camera) { m_camera = camera; };

            /// @brief Sets the renderer of the scene.
            /// @param renderer The renderer to set.
            void setRenderer(std::unique_ptr<ARenderer> renderer) { m_renderer = std::move(renderer); };

            /// @brief Adds a shape to the scene.
            /// @param shape The shape to add, which can be a sphere, a plane and a cone.
            void addShape(std::unique_ptr<AShape> shape) { m_shapes.emplace_back(std::move(shape)); };

            /// @brief Adds a light to the scene.
            /// @param light The light to add, which can be a point light, a directional light and an ambient light.
            void addLight(std::unique_ptr<ALight> light) { m_lights.emplace_back(std::move(light)); };

            /// @brief Gets the camera of the scene.
            [[nodiscard]] Camera& getCamera() { return m_camera; };

            /// @brief Gets the renderer of the scene.
            /// @return A unique pointer to the renderer.
            [[nodiscard]] const std::unique_ptr<ARenderer>& getRenderer() const { return m_renderer; };

            /// @brief Gets the shapes of the scene.
            /// @return A vector of unique pointers to the shapes.
            [[nodiscard]] const std::vector<std::unique_ptr<AShape>>& getShapes() const { return m_shapes; };

            /// @brief Gets the lights of the scene.
            /// @return A vector of unique pointers to the lights.
            [[nodiscard]] const std::vector<std::unique_ptr<ALight>>& getLights() const { return m_lights; };

        private:
            /// @brief The camera of the scene.
            Camera m_camera;

            /// @brief The renderer of the scene.
            std::unique_ptr<ARenderer> m_renderer;

            /// @brief The shapes of the scene.
            std::vector<std::unique_ptr<AShape>> m_shapes;

            /// @brief The lights of the scene.
            std::vector<std::unique_ptr<ALight>> m_lights;

    }; // class Scene

} // namespace RayTracer

#endif //RAYTRACER_SCENE_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Scene
** File description:
** Scene.hpp
*/

#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include <vector>
#include <memory>

#include "RayTracer/Constants.hpp"

#include "RayTracer/Scene/Camera.hpp"

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Factory/RendererFactory.hpp"

namespace RayTracer {

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            void setCamera(const Camera &camera) { m_camera = camera; };
            void setRenderer(const RendererType &rendererType) { m_renderer = RendererFactory::createRenderer(rendererType); };

            void addShape(std::unique_ptr<AShape> shape) { m_shapes.push_back(std::move(shape)); };
            void addLight(std::unique_ptr<ALight> light) { m_lights.push_back(std::move(light)); };

            [[nodiscard]] Camera getCamera() const { return m_camera; };
            [[nodiscard]] const std::unique_ptr<ARenderer> &getRenderer() const { return m_renderer; };
            [[nodiscard]] const std::vector<std::unique_ptr<AShape>> &getShapes() const { return m_shapes; };
            [[nodiscard]] const std::vector<std::unique_ptr<ALight>> &getLights() const { return m_lights; };

        private:
            Camera m_camera;
            std::unique_ptr<ARenderer> m_renderer;

            std::vector<std::unique_ptr<AShape>> m_shapes;
            std::vector<std::unique_ptr<ALight>> m_lights;

    }; // class Scene

} // namespace RayTracer

#endif //RAYTRACER_SCENE_HPP

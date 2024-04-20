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

#include "RayTracer/Abstraction/ALights.hpp"
#include "RayTracer/Abstraction/AShapes.hpp"
#include "RayTracer/Factory/RendererFactory.hpp"

namespace RayTracer {

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            void setName(const std::string &name) { m_renderer->setName(name); };
            void setResolution(std::pair<uint16_t, uint16_t> resolution) { m_renderer->setResolution(resolution); };
            void setCamera(const Camera &camera) { m_camera = camera; };
            void setRenderer(const RendererType &rendererType) { m_renderer = RendererFactory::createRenderer(rendererType); };

            void addShape(std::unique_ptr<AShapes> shape) { m_shapes.push_back(std::move(shape)); };
            void addLight(std::unique_ptr<ALights> light) { m_lights.push_back(std::move(light)); };

            [[nodiscard]] std::pair<uint16_t, uint16_t> getResolution() const { return m_resolution; };
            [[nodiscard]] Camera getCamera() const { return m_camera; };
            [[nodiscard]] const std::unique_ptr<ARenderer> &getRenderer() const { return m_renderer; };
            [[nodiscard]] const std::vector<std::unique_ptr<AShapes>> &getShapes() const { return m_shapes; };
            [[nodiscard]] const std::vector<std::unique_ptr<ALights>> &getLights() const { return m_lights; };

        private:
            std::pair<uint16_t, uint16_t> m_resolution{DEFAULT_WIDTH, DEFAULT_HEIGHT};
            Camera m_camera;
            std::unique_ptr<ARenderer> m_renderer;

            std::vector<std::unique_ptr<AShapes>> m_shapes;
            std::vector<std::unique_ptr<ALights>> m_lights;

    }; // class Scene

} // namespace RayTracer

#endif //RAYTRACER_SCENE_HPP

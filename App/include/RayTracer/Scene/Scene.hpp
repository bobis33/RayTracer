/*
** EPITECH PROJECT, 2024
** Raytracer | Scene
** File description:
** Scene.hpp
*/

#ifndef RAYTRACER_SCENE_HPP
#define RAYTRACER_SCENE_HPP

#include <vector>

#include "RayTracer/Scene/Camera.hpp"
#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Abstraction/AShape.hpp"
#include "RayTracer/Factory/RenderersFactory.hpp"

namespace RayTracer {

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            void setCamera(const Camera &camera) { m_camera = camera; };
            void setRenderer(std::unique_ptr<ARenderer> renderer) { m_renderer = std::move(renderer); };

            void addShape(std::unique_ptr<AShape> shape) { m_shapes.push_back(std::move(shape)); };
            void addLight(std::unique_ptr<ALight> light) { m_lights.push_back(std::move(light)); };
            void addMaterial(std::unique_ptr<AMaterial> material) { m_materials.push_back(std::move(material)); };

            [[nodiscard]] Camera getCamera() const { return m_camera; };
            [[nodiscard]] const std::unique_ptr<ARenderer> &getRenderer() const { return m_renderer; };
            [[nodiscard]] const std::vector<std::unique_ptr<AShape>> &getShapes() const { return m_shapes; };
            [[nodiscard]] const std::vector<std::unique_ptr<ALight>> &getLights() const { return m_lights; };
            [[nodiscard]] const std::vector<std::unique_ptr<AMaterial>> &getMaterials() const { return m_materials; };

        private:
            Camera m_camera;
            std::unique_ptr<ARenderer> m_renderer;
            std::vector<std::unique_ptr<AShape>> m_shapes;
            std::vector<std::unique_ptr<ALight>> m_lights;
            std::vector<std::unique_ptr<AMaterial>> m_materials;

    }; // class Scene

} // namespace RayTracer

#endif //RAYTRACER_SCENE_HPP

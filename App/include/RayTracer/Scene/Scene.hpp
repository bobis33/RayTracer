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

namespace RayTracer {

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            void setName(const std::string &name) { m_name = name; };
            void setResolution(std::pair<uint16_t, uint16_t> resolution) { m_resolution = resolution; };
            void setCamera(const Camera &camera) { m_camera = camera; };
            void setRendererType(const RendererType &rendererType) { m_rendererType = rendererType; };

            void addShape(const std::shared_ptr<AShapes>& shape) { m_shapes.push_back(shape); };
            void addLight(const std::shared_ptr<ALights>& light) { m_lights.push_back(light); };

            [[nodiscard]] std::string getName() const { return m_name; };
            [[nodiscard]] std::pair<uint16_t, uint16_t> getResolution() const { return m_resolution; };
            [[nodiscard]] Camera getCamera() const { return m_camera; };
            [[nodiscard]] RendererType getRendererType() const { return m_rendererType; };
            [[nodiscard]] std::vector<std::shared_ptr<IShapes>> getShapes() const { return m_shapes; };
            [[nodiscard]] std::vector<std::shared_ptr<ILights>> getLights() const { return m_lights; };

        private:
            std::string m_name{"Default Scene Name"};
            std::pair<uint16_t, uint16_t> m_resolution{DEFAULT_WIDTH, DEFAULT_HEIGHT};
            Camera m_camera;
            RendererType m_rendererType{RendererType::SFML};

            std::vector<std::shared_ptr<IShapes>> m_shapes{nullptr};
            std::vector<std::shared_ptr<ILights>> m_lights{nullptr};

    }; // class Scene

} // namespace RayTracer

#endif //RAYTRACER_SCENE_HPP

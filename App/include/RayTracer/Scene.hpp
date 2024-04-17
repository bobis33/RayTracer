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

#include "RayTracer/Abstraction/ILights.hpp"
#include "RayTracer/Abstraction/IShapes.hpp"
#include "RayTracer/Abstraction/IMaterials.hpp"

#include "RayTracer/Constants.hpp"

namespace RayTracer {

    class Camera {
        public:
            Camera() = default;
            ~Camera() = default;

            void setFov(uint16_t fov) { m_fov = fov; };
            void setPosition(uint16_t x, uint16_t y, uint16_t z) { m_position = {x, y, z}; };

            [[nodiscard]] uint16_t getFov() const { return m_fov; };
            [[nodiscard]] std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const { return m_position; };

        private:
            uint16_t m_fov{0};
            std::tuple<uint16_t, uint16_t, uint16_t> m_position{0, 0, 0};

    }; // class Camera

    class Scene {
        public:
            Scene() = default;
            ~Scene() = default;

            void setName(const std::string &name) { m_name = name; };
            void setResolution(uint16_t x, uint16_t y) { m_resolution = {x, y}; };
            void setCamera(const Camera &camera) { m_camera = camera; };

            void addShape(const std::shared_ptr<IShapes>& shape) { m_shapes.push_back(shape); };
            void addMaterial(const std::shared_ptr<IMaterials>& material) { m_materials.push_back(material); };
            void addLight(const std::shared_ptr<ILights>& light) { m_lights.push_back(light); };

            [[nodiscard]] std::string getName() const { return m_name; };
            [[nodiscard]] std::pair<uint16_t, uint16_t> getResolution() const { return m_resolution; };
            [[nodiscard]] Camera getCamera() const { return m_camera; };
            [[nodiscard]] std::vector<std::shared_ptr<IShapes>> getShapes() const { return m_shapes; };
            [[nodiscard]] std::vector<std::shared_ptr<IMaterials>> getMaterials() const { return m_materials; };
            [[nodiscard]] std::vector<std::shared_ptr<ILights>> getLights() const { return m_lights; };

        private:
            std::string m_name{"Scene"};
            std::pair<uint16_t, uint16_t> m_resolution{DEFAULT_WIDTH, DEFAULT_HEIGHT};
            Camera m_camera;

            std::vector<std::shared_ptr<IShapes>> m_shapes{nullptr};
            std::vector<std::shared_ptr<IMaterials>> m_materials{nullptr};
            std::vector<std::shared_ptr<ILights>> m_lights{nullptr};

    }; // class Scene

} // namespace RayTracer

#endif //RAYTRACER_SCENE_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AShapes.cpp
*/

#ifndef RAYTRACER_ASHAPES_HPP
#define RAYTRACER_ASHAPES_HPP

#include <cstdint>
#include <string>
#include <tuple>

#include "RayTracer/Abstraction/IShapes.hpp"

namespace RayTracer {

    enum class ShapeType : uint8_t {
        SPHERE,
        PLANE,
        CYLINDER,
        CONE,
    };

    class AShapes : public IShapes {

        public:
            ~AShapes() override = default;

            void setType(const ShapeType& type) { m_type = type; };
            void setMaterial(const std::string& material) { m_material = material; };
            void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t>& position) { m_position = position; };

            ShapeType getType() const { return m_type; };
            std::string getMaterial() const { return m_material; };
            std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const { return m_position; };

        private:
            ShapeType m_type;
            std::string m_material;
            std::tuple<uint16_t, uint16_t, uint16_t> m_position{0, 0, 0};

    }; // class AShapes

} // namespace RayTracer

#endif //RAYTRACER_ASHAPES_HPP

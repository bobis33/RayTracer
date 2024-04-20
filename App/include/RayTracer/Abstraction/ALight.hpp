/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ALight.cpp
*/

#ifndef RAYTRACER_ALIGHT_HPP
#define RAYTRACER_ALIGHT_HPP

#include <tuple>
#include <cstdint>

#include "RayTracer/Abstraction/ILight.hpp"

namespace RayTracer {

    class ALight : public ILight {

        public:
            ~ALight() override = default;

            void setType(const LightType &type) override { m_type = type; };
            void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t> &position) override { m_position = position; };

            [[nodiscard]] LightType getType() const override { return m_type; };
            [[nodiscard]] std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const override { return m_position; };

        private:
            LightType m_type{LightType::NONE};
            std::tuple<uint16_t, uint16_t, uint16_t> m_position{0, 0, 0};

    }; // ALight

} // namespace RayTracer

#endif //RAYTRACER_ALIGHT_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ALights.cpp
*/

#ifndef RAYTRACER_ALIGHTS_HPP
#define RAYTRACER_ALIGHTS_HPP

#include <tuple>
#include <cstdint>

#include "RayTracer/Abstraction/ILights.hpp"

namespace RayTracer {

    class ALights : public ILights {

        public:
            ~ALights() override = default;

            void setType(const LightType &type) override { m_type = type; };
            void setPosition(const std::tuple<uint16_t, uint16_t, uint16_t> &position) override { m_position = position; };

            [[nodiscard]] LightType getType() const override { return m_type; };
            [[nodiscard]] std::tuple<uint16_t, uint16_t, uint16_t> getPosition() const override { return m_position; };

        private:
            LightType m_type{LightType::NONE};
            std::tuple<uint16_t, uint16_t, uint16_t> m_position{0, 0, 0};

    }; // ALights

} // namespace RayTracer

#endif //RAYTRACER_ALIGHTS_HPP

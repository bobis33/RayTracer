/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ALight.cpp
*/

#ifndef RAYTRACER_ALIGHT_HPP
#define RAYTRACER_ALIGHT_HPP

#include "RayTracer/Abstraction/ILight.hpp"

namespace RayTracer {

    class ALight : public ILight {

        public:
            ~ALight() override = default;

            void setType(const LightType &type) override { m_type = type; };

            [[nodiscard]] LightType getType() const override { return m_type; };
            [[nodiscard]] Vector& getPosition() override { return m_position; };
            [[nodiscard]] Color& getColor() override { return m_color; }

        private:
            LightType m_type{LightType::NONE};
            Vector m_position{0, 0, 0};
            Color m_color{0, 0, 0};

    }; // class ALight

} // namespace RayTracer

#endif //RAYTRACER_ALIGHT_HPP

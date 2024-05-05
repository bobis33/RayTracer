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
            void setIntensity(const float &intensity) override { m_intensity = intensity; };

            [[nodiscard]] const LightType& getType() const override { return m_type; };
            [[nodiscard]] Vector& getPosition() override { return m_position; };
            [[nodiscard]] Vector& getDirection() override { return m_direction; };
            [[nodiscard]] Color& getColor() override { return m_color; };
            [[nodiscard]] float& getIntensity() override { return m_intensity; };

        private:
            LightType m_type{LightType::NONE};
            Vector m_position{0, 0, 0};
            Vector m_direction{0, 0, 0};
            Color m_color{0, 0, 0};
            float m_intensity{0};

    }; // class ALight

} // namespace RayTracer

#endif //RAYTRACER_ALIGHT_HPP

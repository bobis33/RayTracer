/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ALight.cpp
*/

/// @file ALight.hpp
#ifndef RAYTRACER_ALIGHT_HPP
#define RAYTRACER_ALIGHT_HPP

#include "RayTracer/Abstraction/ILight.hpp"

namespace rtr {

    /// @class ALight
    /// @brief An abstract class for lights.
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

            /// @brief The type of the light.
            LightType m_type{LightType::NONE};

            /// @brief The position of the light.
            Vector m_position{0, 0, 0};

            /// @brief The direction of the light.
            Vector m_direction{0, 0, 0};

            /// @brief The color of the light.
            Color m_color{0, 0, 0};

            /// @brief The intensity of the light.
            float m_intensity{0};

    }; // class ALight

} // namespace RayTracer

#endif //RAYTRACER_ALIGHT_HPP

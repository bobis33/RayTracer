/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** AMaterial.hpp
*/

/// @file AMaterial.hpp
#ifndef RAYTRACER_AMATERIAL_HPP
#define RAYTRACER_AMATERIAL_HPP

#include "RayTracer/Abstraction/IMaterial.hpp"

namespace rtr {

    /// @class AMaterial
    /// @brief An abstract class for materials, based on the interface IMaterials.
    class AMaterial : public IMaterial {

        public:

            ~AMaterial() override = default;

            void setType(const MaterialType &type) override { m_type = type; };
            void setReflectivity(const float &reflectivity) override { m_reflectivity = reflectivity; };
            void setTransparency(const float &transparency) override { m_transparency = transparency; };

            [[nodiscard]] const MaterialType& getType() const override { return m_type; };
            [[nodiscard]] Color& getColor() override { return m_color; };
            [[nodiscard]] const float& getReflectivity() const override { return m_reflectivity; };
            [[nodiscard]] const float& getTransparency() const override { return m_transparency; };

        private:

            /// @brief The type of the material.
            MaterialType m_type{MaterialType::NONE};

            /// @brief The color of the material.
            Color m_color{Color::getBlack()};

            /// @brief The reflectivity of the material.
            float m_reflectivity{0.0F};

            /// @brief The transparency of the material.
            float m_transparency{0.0F};

    }; // class AMaterial

}; // namespace 

#endif //RAYTRACER_AMATERIAL_HPP

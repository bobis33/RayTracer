/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** AMaterial.hpp
*/

#ifndef RAYTRACER_AMATERIAL_HPP
#define RAYTRACER_AMATERIAL_HPP

#include "RayTracer/Abstraction/IMaterial.hpp"

namespace RayTracer {

    class AMaterial : public IMaterial {

        public:

            ~AMaterial() override = default;

            void setType(const MaterialType &type) override { m_type = type; };
            void setReflectivity(const uint8_t &reflectivity) override { m_reflectivity = reflectivity; };
            void setTransparency(const uint8_t &transparency) override { m_transparency = transparency; };

            [[nodiscard]] MaterialType getType() const override { return m_type; };
            [[nodiscard]] Color& getColor() override { return m_color; };
            [[nodiscard]] float getReflectivity() const override { return m_reflectivity; };
            [[nodiscard]] float getTransparency() const override { return m_transparency; };

        private:
            MaterialType m_type{MaterialType::NONE};
            Color m_color{Color::getBlack()};
            float m_reflectivity{0.0F};
            float m_transparency{0.0F};

    }; // class AMaterial

}; // namespace 

#endif //RAYTRACER_AMATERIAL_HPP

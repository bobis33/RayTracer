/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** AMaterials
*/

#ifndef RAYTRACER_AMATERIALS_HPP
#define RAYTRACER_AMATERIALS_HPP

#include "RayTracer/Abstraction/IMaterials.hpp"

namespace RayTracer {

    class AMaterials : public IMaterials {

        public:

            ~AMaterials() override = default;

            void setType(const MaterialType &type) override { m_type = type; };
            void setColor(const Color_t &color) override { m_color = color; };
            void setReflectivity(const uint8_t &reflectivity) override { m_reflectivity = reflectivity; };
            void setTransparency(const uint8_t &transparency) override { m_transparency = transparency; };

            [[nodiscard]] MaterialType getType() const override { return m_type; };
            [[nodiscard]] Color_t getColor() const override { return m_color; };
            [[nodiscard]] uint8_t getReflectivity() const override { return m_reflectivity; };
            [[nodiscard]] uint8_t getTransparency() const override { return m_transparency; };

        private:
            MaterialType m_type{MaterialType::NONE};
            Color_t m_color{BLACK};
            uint8_t m_reflectivity{0};
            uint8_t m_transparency{0};


    }; // class AMaterials

}; // namespace 

#endif //RAYTRACER_AMATERIALS_HPP

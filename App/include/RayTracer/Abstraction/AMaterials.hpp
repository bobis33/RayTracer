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

            [[nodiscard]] MaterialType getType() const override { return m_type; };

        private:
            MaterialType m_type{MaterialType::NONE};


    }; // class AMaterials

}; // namespace 

#endif //RAYTRACER_AMATERIALS_HPP

/*
** EPITECH PROJECT, 2024
** Raytracer | Reflective
** File description:
** Reflective.hpp
*/

#ifndef RAYTRACER_REFLECTIVE_HPP
#define RAYTRACER_REFLECTIVE_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"

namespace rtr {

    class Reflective : public AMaterial {

        public:
            ~Reflective() override = default;

            void applyMaterial(Color* color) override {
                (void) color;
                // reflected_color = object_color * reflectivity + environment_color * (1 - reflectivity);
                // final_color = object_color * (1 - reflectivity) + reflected_color * reflectivity;
                // color->setColor(final_color);
            };

            [[nodiscard]] std::string getPluginName() const override { return REFLECTIVE_MATERIAL; };

    }; // class Reflective

} // namespace RayTracer

#endif // RAYTRACER_REFLECTIVE_HPP

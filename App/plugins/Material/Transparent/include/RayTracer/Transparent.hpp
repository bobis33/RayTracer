/*
** EPITECH PROJECT, 2024
** Raytracer | Transparent
** File description:
** Transparent.hpp
*/

#ifndef RAYTRACER_TRANSPARENT_HPP
#define RAYTRACER_TRANSPARENT_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"

namespace rtr {

    class Transparent : public AMaterial {

        public:
            ~Transparent() override = default;

            void applyMaterial(Color* color) override {
                uint8_t r = static_cast<uint8_t>(color->getValue().r * (1 - this->getTransparency()));
                uint8_t g = static_cast<uint8_t>(color->getValue().g * (1 - this->getTransparency()));
                uint8_t b = static_cast<uint8_t>(color->getValue().b * (1 - this->getTransparency()));

                color->setColor(r, g, b);

                /*   ALPHA BLENDING
                 *
                 *  r = c1.r * c1.a + c2.r * c2.a * (1 - c1.a)
                 *  g = c1.g * c1.a + c2.g * c2.a * (1 - c1.a)
                 *  b = c1.b * c1.a + c2.b * c2.a * (1 - c1.a)
                 *  a = c1.a + c2.a * (1 - c1.a)
                 *
                 */
            };

            [[nodiscard]] std::string getPluginName() const override { return TRANSPARENT_MATERIAL; };

    }; // class Transparent

} // namespace RayTracer

#endif // RAYTRACER_TRANSPARENT_HPP

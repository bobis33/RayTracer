/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** CompositeMaterial.hpp
*/

#ifndef RAYTRACER_COMPOSITE_MATERIAL_HPP
#define RAYTRACER_COMPOSITE_MATERIAL_HPP

#include <vector>
#include <memory>

#include "RayTracer/Abstraction/AMaterial.hpp"

namespace RayTracer {

    class CompositeMaterial : public AMaterial {

        public:

            ~CompositeMaterial() override = default;

            [[nodiscard]] std::string getPluginName() const override { return COMPOSITE_MATERIAL; };

            void addMaterial(std::unique_ptr<AMaterial> material) { m_materials.push_back(std::move(material)); };

            void applyMaterial(Color* color) override {
                for (const auto& material : m_materials) {
                    material->applyMaterial(color);
                }
                this->getMaterial().setColor(color->getValue());
            }

        private:
            std::vector<std::unique_ptr<AMaterial>> m_materials;

    }; // class CompositeMaterial

}; // namespace RayTracer

#endif //RAYTRACER_COMPOSITE_MATERIAL_HPP

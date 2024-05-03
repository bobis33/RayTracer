/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** CompositeMaterial
*/

#ifndef RAYTRACER_COMPOSITE_MATERIAL_HPP
#define RAYTRACER_COMPOSITE_MATERIAL_HPP

#include <vector>
#include <memory>

#include "RayTracer/Abstraction/AMaterial.hpp"

namespace RayTracer {

    class CompositeMaterial : public AMaterial {

        public:

            CompositeMaterial() = default;
            ~CompositeMaterial() = default;

            void addMaterial(std::unique_ptr<AMaterial> material) { m_materials.push_back(std::move(material)); };

            /*
                void doSomething() {
                for (auto &material : m_materials) {
                    material->doSomething();
                }
             */

        private:
            std::vector<std::unique_ptr<AMaterial>> m_materials;


    }; // class CompositeMaterial

}; // namespace RayTracer

#endif //RAYTRACER_COMPOSITE_MATERIAL_HPP

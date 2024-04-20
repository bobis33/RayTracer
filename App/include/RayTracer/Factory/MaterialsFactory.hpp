/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** MaterialsFactory
*/

#ifndef RAYTRACER_MATERIALSFACTORY_HPP
#define RAYTRACER_MATERIALSFACTORY_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/PluginLoader.hpp"

namespace RayTracer {

    class MaterialsFactory {
        public:
            static std::unique_ptr<AMaterial> createMaterials(const MaterialType &type)
            {
                std::unique_ptr<AMaterial> material;
                switch (type) {
                    case MaterialType::COLOR:
                        material = PluginLoader::loadPlugin<AMaterial>("./plugins/raytracer_color_material.so");
                        break;
                    default:
                        throw RunTimeException("Materials type not found");
                }
                material->setType(type);
                return material;
            };


        private:


    }; // class MaterialsFactory

}; // namespace RayTracer

#endif //RAYTRACER_MATERIALSFACTORY_HPP

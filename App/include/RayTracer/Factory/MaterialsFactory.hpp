/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** MaterialsFactory
*/

#ifndef RAYTRACER_MATERIALSFACTORY_HPP
#define RAYTRACER_MATERIALSFACTORY_HPP

#include "RayTracer/Abstraction/AMaterials.hpp"
#include "RayTracer/PluginLoader.hpp"

namespace RayTracer {

    class MaterialsFactory {
        public:
            static std::unique_ptr<AMaterials> createMaterials(const MaterialType &type)
            {
                std::unique_ptr<AMaterials> materials;
                switch (type) {
                    case MaterialType::COLOR:
                        materials = PluginLoader::loadPlugin<AMaterials>("./plugins/raytracer_color_material.so");
                        break;
                    default:
                        throw RunTimeException("Materials type not found");
                }
                materials->setType(type);
                return materials;
            };


        private:


    }; // class MaterialsFactory

}; // namespace RayTracer

#endif //RAYTRACER_MATERIALSFACTORY_HPP

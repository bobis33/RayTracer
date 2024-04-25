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
            static std::unique_ptr<AMaterial> createMaterials(const MaterialType &type,
                                                              const Color_t &color,
                                                              const std::string &name)
            {
                std::unique_ptr<AMaterial> material;
                switch (type) {
                    case MaterialType::COLOR:
                        material = PluginLoader::loadPlugin<AMaterial>("./plugins/material_color.so");
                        break;
                    default:
                        throw RunTimeException("Materials type not found");
                }
                material->setType(type);
                material->getColor().setColor(color);
                material->setName(name);
                return material;
            };


        private:


    }; // class MaterialsFactory

}; // namespace RayTracer

#endif //RAYTRACER_MATERIALSFACTORY_HPP

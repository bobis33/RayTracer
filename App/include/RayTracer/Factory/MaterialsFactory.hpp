/*
** EPITECH PROJECT, 2024
** raytracer | materialsFactory
** File description:
** MaterialsFactory
*/

#ifndef RAYTRACER_MATERIALSFACTORY_HPP
#define RAYTRACER_MATERIALSFACTORY_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/Loader/PluginLoader.hpp"

namespace RayTracer {

    class MaterialsFactory {
        public:
            static std::unique_ptr<AMaterial> createMaterials(const MaterialType &type,
                                                              const color_t &color,
                                                              const std::string &name)
            {
                std::unique_ptr<AMaterial> material;
                switch (type) {
                    case MaterialType::COLOR:
                        material = PluginLoader::getInstance().getPlugin<AMaterial>("FlatColor");
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

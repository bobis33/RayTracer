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
                                                              const Color &color);

    }; // class MaterialsFactory

}; // namespace RayTracer

#endif //RAYTRACER_MATERIALSFACTORY_HPP

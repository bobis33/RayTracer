/*
** EPITECH PROJECT, 2024
** raytracer | Factory
** File description:
** Material.hpp
*/

#ifndef RAYTRACER_MATERIAL_FACTORY_HPP
#define RAYTRACER_MATERIAL_FACTORY_HPP

#include "RayTracer/Abstraction/AMaterial.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace rtr {

    class MaterialFactory {

        public:

            static std::unique_ptr<AMaterial> createMaterial(const MaterialType &type,
                                                             const float &floatValue);

    }; // class MaterialFactory

}; // namespace RayTracer

#endif //RAYTRACER_MATERIAL_FACTORY_HPP

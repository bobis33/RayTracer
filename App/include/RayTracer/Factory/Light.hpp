/*
** EPITECH PROJECT, 2024
** Raytracer | Factory
** File description:
** Light.hpp
*/

#ifndef RAYTRACER_LIGHT_FACTORY_HPP
#define RAYTRACER_LIGHT_FACTORY_HPP

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Loader/Plugin.hpp"

namespace RayTracer {

    class LightFactory {

        public:
            static std::unique_ptr<ALight> createLight(const LightType &type,
                                                       const Vector &position,
                                                       const Color &color);

    }; // class LightFactory

} // namespace RayTracer

#endif //RAYTRACER_LIGHT_FACTORY_HPP

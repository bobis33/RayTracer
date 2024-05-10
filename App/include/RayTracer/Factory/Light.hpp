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

namespace rtr {

    class LightFactory {

        public:
            static std::unique_ptr<ALight> createLight(const Color &color,
                                                       const float &intensity);
            static std::unique_ptr<ALight> createLight(const LightType &type,
                                                       const Color &color,
                                                       const float &intensity,
                                                       const Vector &vector);

    }; // class LightFactory

} // namespace RayTracer

#endif //RAYTRACER_LIGHT_FACTORY_HPP

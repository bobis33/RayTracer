/*
** EPITECH PROJECT, 2024
** Raytracer | lightsFactory
** File description:
** LightsFactory.hpp
*/

#ifndef RAYTRACER_LIGHTS_FACTORY_HPP
#define RAYTRACER_LIGHTS_FACTORY_HPP

#include "RayTracer/Abstraction/ALight.hpp"
#include "RayTracer/Loader/PluginLoader.hpp"

namespace RayTracer {

    class LightsFactory {

        public:
            static std::unique_ptr<ALight> createLights(const LightType &type,
                                                        const Vector &position,
                                                        const Color &color);

    }; // class LightsFactory

} // namespace RayTracer

#endif //RAYTRACER_LIGHTS_FACTORY_HPP

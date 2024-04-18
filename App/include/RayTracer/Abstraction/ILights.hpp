/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILights.cpp
*/

#ifndef RAYTRACER_ILIGHTS_HPP
#define RAYTRACER_ILIGHTS_HPP

namespace RayTracer {

    enum class LightType : uint8_t {
        AMBIENT,
        DIRECTIONAL,
        NONE
    };

    class ILights {

        public:
            virtual ~ILights() = default;

    }; // ILights

} // namespace RayTracer

#endif //RAYTRACER_ILIGHTS_HPP

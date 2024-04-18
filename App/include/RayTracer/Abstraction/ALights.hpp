/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ALights.cpp
*/

#ifndef RAYTRACER_ALIGHTS_HPP
#define RAYTRACER_ALIGHTS_HPP

#include <tuple>
#include <stdint.h>

#include "RayTracer/Abstraction/ILights.hpp"

namespace RayTracer {

    class ALights : public ILights {

        public:
            ~ALights() override = default;

        private:
            LightType m_type{LightType::NONE};
            std::tuple<uint16_t, uint16_t, uint16_t> position{0, 0, 0};

    }; // ALights

} // namespace RayTracer

#endif //RAYTRACER_ALIGHTS_HPP

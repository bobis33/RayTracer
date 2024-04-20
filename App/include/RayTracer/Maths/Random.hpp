/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Random.hpp
*/

#ifndef RAYTRACER_RANDOM_HPP
#define RAYTRACER_RANDOM_HPP

#include <random>

namespace RayTracer {

    class Random {

        public:

            static int randomInt(int min, int max) {
                std::mt19937 gen(std::random_device{}());
                std::uniform_int_distribution<> dis(min, max);
                return dis(gen);
            }

            static int randomInt() {
                return randomInt(0, 1000);
            }

            static float randomFloat(float min, float max) {
                return min + static_cast<float>(randomInt(0, 1000)) / 1000.0f * (max - min);

            };

            static float randomFloat() {
                return randomFloat(0.0f, 1.0f);
            }

    }; // class Random

} // namespace RayTracer

#endif // RAYTRACER_RANDOM_HPP

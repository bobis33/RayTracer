/*
** EPITECH PROJECT, 2024
** lib
** File description:
** random.cpp
*/

#include "myLib/Random.hpp"

int Random::randomInt(int min, int max)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

float Random::randomFloat(float min, float max)
{
    return min + static_cast<float>(randomInt(-1000, 1000)) / 1000.0f * (max - min);
}

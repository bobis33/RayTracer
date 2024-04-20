/*
** EPITECH PROJECT, 2024
** lib
** File description:
** random.cpp
*/

#include "Maths/Random.hpp"

int Random::randomInt(int min, int max)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int Random::randomInt()
{
    return randomInt(0, 1000);
}

float Random::randomFloat(float min, float max)
{
    return min + static_cast<float>(randomInt(0, 1000)) / 1000.0f * (max - min);
}

float Random::randomFloat()
{
    return randomFloat(0.0f, 1.0f);
}
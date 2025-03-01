/*
** EPITECH PROJECT, 2024
** lib
** File description:
** Random.hpp
*/

#ifndef LIB_RANDOM_HPP
#define LIB_RANDOM_HPP

#include <random>

class Random {
    public:

    static int randomInt(int min, int max);
    static int randomInt() { return randomInt(-1000, 1000); };

    static float randomFloat(float min, float max);
    static float randomFloat() { return randomFloat(-1.0f, 1.0f); };

}; // class Random


#endif // LIB_RANDOM_HPP

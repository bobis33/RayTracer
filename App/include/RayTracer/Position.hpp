/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Position.hpp
*/

#ifndef RAYTRACER_POSITION_HPP
#define RAYTRACER_POSITION_HPP

#include <cstdint>

namespace RayTracer {

    using Position_t = struct Position_s {
        int16_t x;
        int16_t y;
        int16_t z;
    };

    class Position {

        public:
            Position() : m_position{0, 0, 0} {};
            Position(const int16_t &x, const int16_t &y, const int16_t &z) : m_position{x, y, z} {};
            explicit Position(const Position_t &position) : m_position(position) {};
            ~Position() = default;

            void setX(const int16_t &x) { m_position.x = x; };
            void setY(const int16_t &y) { m_position.y = y; };
            void setZ(const int16_t &z) { m_position.z = z; };
            void setPosition(const int16_t &x, const int16_t &y, const int16_t &z) { m_position = {x, y, z}; };
            void setPosition(const Position_t &position) { m_position = position; };

            [[nodiscard]] int16_t getX() const { return m_position.x; };
            [[nodiscard]] int16_t getY() const { return m_position.y; };
            [[nodiscard]] int16_t getZ() const { return m_position.z; };
            [[nodiscard]] Position_t getPosition() const { return m_position; };

        private:
            Position_t m_position{0, 0, 0};

    }; // class Position

}; // namespace RayTracer

#endif //RAYTRACER_POSITION_HPP

/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector.hpp
*/

#ifndef RAYTRACER_VECTOR_HPP
#define RAYTRACER_VECTOR_HPP

#include <cstdint>
#include <cmath>

namespace RayTracer {

    using vector_t = struct vector_s {
        int16_t x;
        int16_t y;
        int16_t z;
    };

    class Vector {

        public:
            Vector() : m_position{0, 0, 0} {};
            Vector(const int16_t &x, const int16_t &y, const int16_t &z) : m_position(x, y, z) {};
            explicit Vector(const vector_t &position) : m_position(position) {};
            ~Vector() = default;

            void setX(const int16_t &x) { m_position.x = x; };
            void setY(const int16_t &y) { m_position.y = y; };
            void setZ(const int16_t &z) { m_position.z = z; };
            void setVector(const int16_t &x, const int16_t &y, const int16_t &z) { m_position = {x, y, z}; };
            void setVector(const vector_t &position) { m_position = position; };

            [[nodiscard]] int16_t getX() const { return m_position.x; };
            [[nodiscard]] int16_t getY() const { return m_position.y; };
            [[nodiscard]] int16_t getZ() const { return m_position.z; };
            [[nodiscard]] vector_t getValue() const { return m_position; };

            Vector operator+(const Vector &other) const {
                return {
                    static_cast<int16_t>(m_position.x + other.getX()),
                    static_cast<int16_t>(m_position.y + other.getY()),
                    static_cast<int16_t>(m_position.z + other.getZ())
                };
            };
            Vector operator-(const Vector &other) const {
                return {
                    static_cast<int16_t>(m_position.x - other.getX()),
                    static_cast<int16_t>(m_position.y - other.getY()),
                    static_cast<int16_t>(m_position.z - other.getZ())
                };
            };
            Vector operator*(int16_t v) const {
                return Vector(
                    m_position.x * v,
                    m_position.y * v,
                    m_position.z * v
                );
            };

            [[nodiscard]] double length() const { return sqrt(m_position.x * m_position.x + m_position.y * m_position.y + m_position.z * m_position.z); };

            [[nodiscard]] int dot(const Vector &other) const { return m_position.x * other.getX() + m_position.y * other.getY() + m_position.z * other.getZ(); };

            [[nodiscard]] Vector cross(const Vector &other) const { return {
                    static_cast<int16_t>(m_position.y * other.getZ() - m_position.z * other.getY()),
                    static_cast<int16_t>(m_position.z * other.getX() - m_position.x * other.getZ()),
                    static_cast<int16_t>(m_position.x * other.getY() - m_position.y * other.getX())
                };
            };

            Vector normalize() const {
                double len = length();
                return {
                    static_cast<int16_t>(m_position.x / len),
                    static_cast<int16_t>(m_position.y / len),
                    static_cast<int16_t>(m_position.z / len)
                };
            };

        private:
            vector_t m_position{0, 0, 0};

    }; // class Vector

}; // namespace RayTracer

#endif //RAYTRACER_VECTOR_HPP

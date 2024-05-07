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
        double x;
        double y;
        double z;
    };

    class Vector {

        public:
            Vector() : m_position{0, 0, 0} {};
            Vector(const double &x, const double &y, const double &z) : m_position(x, y, z) {};
            explicit Vector(const vector_t &position) : m_position(position) {};
            ~Vector() = default;

            void setX(const double &x) { m_position.x = x; };
            void setY(const double &y) { m_position.y = y; };
            void setZ(const double &z) { m_position.z = z; };
            void setVector(const double &x, const double &y, const double &z) { m_position = {x, y, z}; };
            void setVector(const vector_t &position) { m_position = position; };

            [[nodiscard]] double getX() const { return m_position.x; };
            [[nodiscard]] double getY() const { return m_position.y; };
            [[nodiscard]] double getZ() const { return m_position.z; };
            [[nodiscard]] vector_t getValue() const { return m_position; };

            Vector operator+(const Vector &other) const {
                return {
                    static_cast<double>(m_position.x + other.getX()),
                    static_cast<double>(m_position.y + other.getY()),
                    static_cast<double>(m_position.z + other.getZ())
                };
            };
            Vector operator-(const Vector &other) const {
                return {
                    static_cast<double>(m_position.x - other.getX()),
                    static_cast<double>(m_position.y - other.getY()),
                    static_cast<double>(m_position.z - other.getZ())
                };
            };
            Vector operator*(const Vector &other) const {
                return {
                        static_cast<double>(m_position.x * other.getX()),
                        static_cast<double>(m_position.y * other.getY()),
                        static_cast<double>(m_position.z * other.getZ())
                };
            };

            [[nodiscard]] double length() const { return sqrt(m_position.x * m_position.x + m_position.y * m_position.y + m_position.z * m_position.z); };

            [[nodiscard]] double dot(const Vector &other) const { return m_position.x * other.getX() + m_position.y * other.getY() + m_position.z * other.getZ(); };

            [[nodiscard]] Vector cross(const Vector &other) const { return {
                    (m_position.y * other.getZ() - m_position.z * other.getY()),
                    (m_position.z * other.getX() - m_position.x * other.getZ()),
                    (m_position.x * other.getY() - m_position.y * other.getX())
                };
            };

            [[nodiscard]] Vector normalize() const {
                double len = length();
                return {
                    static_cast<double>(m_position.x / len),
                    static_cast<double>(m_position.y / len),
                    static_cast<double>(m_position.z / len)
                };
            };

        private:
            vector_t m_position{0, 0, 0};

    }; // class Vector

}; // namespace RayTracer

#endif //RAYTRACER_VECTOR_HPP

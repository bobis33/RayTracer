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

    class Vector3D {
    public:
        double x, y, z;

        Vector3D() : x(0), y(0), z(0) {}
        Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

        double length() const {
            return std::sqrt(x*x + y*y + z*z);
        }

        Vector3D operator+(const Vector3D& other) const {
            return Vector3D(x + other.x, y + other.y, z + other.z);
        }

        Vector3D operator-(const Vector3D& other) const {
            return Vector3D(x - other.x, y - other.y, z - other.z);
        }

        Vector3D operator*(double scalar) const {
            return Vector3D(x * scalar, y * scalar, z * scalar);
        }

        Vector3D operator/(double scalar) const {
            return Vector3D(x / scalar, y / scalar, z / scalar);
        }

        double dot(const Vector3D& other) const {
            return x * other.x + y * other.y + z * other.z;
        }
    }; // class Vector3D

    class Point3D {
    public:
        double x, y, z;

        Point3D() : x(0), y(0), z(0) {}
        Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

        Point3D operator+(const Vector3D& vector) const {
            return Point3D(x + vector.x, y + vector.y, z + vector.z);
        }

        Point3D operator-(const Point3D& other) const {
            return Point3D(x - other.x, y - other.y, z - other.z);
        }
    }; // class Point3D

    class Rectangle3D {
    public:
        Point3D origin;
        Vector3D bottom_side, left_side;

        Rectangle3D(const Point3D& origin, const Vector3D& bottom_side, const Vector3D& left_side)
            : origin(origin), bottom_side(bottom_side), left_side(left_side) {}

        Point3D pointAt(double u, double v) const {
            return origin + bottom_side * u + left_side * v;
        }
    }; // class Rectangle3D

}; // namespace RayTracer

#endif //RAYTRACER_VECTOR_HPP

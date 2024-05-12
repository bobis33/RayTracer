/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector.hpp
*/

/// @file Vector.hpp
#ifndef RAYTRACER_VECTOR_HPP
#define RAYTRACER_VECTOR_HPP

#include <cstdint>
#include <cmath>

namespace rtr {

    /// @struct vector_s Vector.hpp
    /// @brief A struct representing a 3D vector.
    /// @brief Type alias for a 3D vector.
    using vector_t = struct vector_s {
        /// @brief The x-component of the vector.
        double x;
        /// @brief The y-component of the vector.
        double y;
        /// @brief The z-component of the vector.
        double z;
    };

    class Vector {

        public:
            Vector() : m_position{0, 0, 0} {};
            Vector(const double x, const double y, const double z) : m_position{x, y, z} {};
            explicit Vector(const vector_t position) : m_position{position} {};
            ~Vector() = default;

            /// @brief Sets the x-component of the vector.
            /// @param x The x-component to set.
            void setX(const double x) { m_position.x = x; };

            /// @brief Sets the y-component of the vector.
            /// @param y The y-component to set.
            void setY(const double y) { m_position.y = y; };

            /// @brief Sets the z-component of the vector.
            /// @param z The z-component to set.
            void setZ(const double z) { m_position.z = z; };

            /// @brief Sets the vector to the given x, y, and z values.
            /// @param x The x-component of the vector.
            /// @param y The y-component of the vector.
            /// @param z The z-component of the vector.
            void setVector(const double x, const double y, const double z) { m_position = {x, y, z}; };

            /// @brief Sets the vector to the given vector struct.
            /// @param position The vector struct to set.
            void setVector(const vector_t &position) { m_position = position; };

            /// @brief Gets the x-component of the vector.
            /// @return The x-component of the vector.
            [[nodiscard]] double getX() const { return m_position.x; };

            /// @brief Gets the y-component of the vector.
            /// @return The y-component of the vector.
            [[nodiscard]] double getY() const { return m_position.y; };

            /// @brief Gets the z-component of the vector.
            /// @return The z-component of the vector.
            [[nodiscard]] double getZ() const { return m_position.z; };

            /// @brief Gets the vector as a struct.
            /// @return The vector struct.
            [[nodiscard]] vector_t getValue() const { return m_position; };

            /// @brief Adds two vectors.
            /// @param other The other vector to add.
            /// @return The sum of the two vectors.
            Vector operator+(const Vector &other) const {
                return {
                    m_position.x + other.getX(),
                    m_position.y + other.getY(),
                    m_position.z + other.getZ()
                };
            };

            /// @brief Adds a scalar to the vector.
            /// @param scalar The scalar to add.
            /// @return The sum of the vector and the scalar.
            Vector operator+(const double scalar) const {
                return {
                    m_position.x + scalar,
                    m_position.y + scalar,
                    m_position.z + scalar
                };
            };

            /// @brief Subtracts two vectors.
            /// @param other The other vector to subtract.
            /// @return The difference of the two vectors.
            Vector operator-(const Vector &other) const {
                return {
                    m_position.x - other.getX(),
                    m_position.y - other.getY(),
                    m_position.z - other.getZ()
                };
            };

            /// @brief Multiplies two vectors.
            /// @param other The other vector to multiply.
            /// @return The product of the two vectors.
            Vector operator*(const Vector &other) const {
                return {
                        m_position.x * other.getX(),
                        m_position.y * other.getY(),
                        m_position.z * other.getZ()
                };
            };

            /// @brief Multiplies the vector by a scalar.
            /// @param scalar The scalar to multiply by.
            /// @return The product of the vector and the scalar.
            Vector operator*(const double scalar) const {
                return {
                    m_position.x * scalar,
                    m_position.y * scalar,
                    m_position.z * scalar
                };
            };

            /// @brief Divides the vector by a scalar.
            /// @param scalar The scalar to divide by.
            /// @return The quotient of the vector and the scalar.
            Vector operator/(const double scalar) const {
                return {
                    m_position.x / scalar,
                    m_position.y / scalar,
                    m_position.z / scalar
                };
            };

            /// @brief Gets the length of the vector.
            /// @return The length of the vector.
            [[nodiscard]] double length() const { return sqrt(m_position.x * m_position.x + m_position.y * m_position.y + m_position.z * m_position.z); };

            /// @brief Calculates the dot product of the vector and another vector.
            /// @param other The other vector to calculate the dot product with.
            /// @return The dot product of the two vectors.
            [[nodiscard]] double dot(const Vector &other) const { return m_position.x * other.getX() + m_position.y * other.getY() + m_position.z * other.getZ(); };

            /// @brief Calculates the cross product of the vector and another vector.
            /// @param other The other vector to calculate the cross product with.
            /// @return The cross product of the two vectors.
            [[nodiscard]] Vector cross(const Vector &other) const { return {
                    m_position.y * other.getZ() - m_position.z * other.getY(),
                    m_position.z * other.getX() - m_position.x * other.getZ(),
                    m_position.x * other.getY() - m_position.y * other.getX()
                };
            };

            /// @brief Normalizes the vector.
            /// @return The normalized vector.
            [[nodiscard]] Vector normalize() const {
                const double len = length();
                return {
                    m_position.x / len,
                    m_position.y / len,
                    m_position.z / len
                };
            };

        private:

            /// @brief The vector as a struct.
            vector_t m_position{0, 0, 0};

    }; // class Vector

}; // namespace RayTracer

#endif //RAYTRACER_VECTOR_HPP

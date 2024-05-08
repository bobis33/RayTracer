/*
** EPITECH PROJECT, 2024
** raytracer | utils
** File description:
** Rectangle3D.hpp
*/

#ifndef RAYTRACER_RECTANGLE3D_HPP
#define RAYTRACER_RECTANGLE3D_HPP

#include "RayTracer/Utils/Vector.hpp"

namespace RayTracer {

    class Rectangle3D {

        public:

            Rectangle3D() = default;
            Rectangle3D(const Vector& origin, const Vector& bottom_side, const Vector& left_side)
                : m_origin(origin), m_bottom_side(bottom_side), m_left_side(left_side) {};

            ~Rectangle3D() = default;

            [[nodiscard]] Vector pointAt(double u, double v) const { return m_origin + m_bottom_side * u + m_left_side * v; };

        private:

            Vector m_origin{0, 0, 0};
            Vector m_bottom_side{0, 0, 0};
            Vector m_left_side{0, 0, 0};

    }; // class Rectangle3D

}; // namespace RayTracer

#endif // RAYTRACER_RECTANGLE3D_HPP

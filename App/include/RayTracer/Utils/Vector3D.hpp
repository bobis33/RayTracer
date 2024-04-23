/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-raytracer-paul.ragueneau
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

class Vector3D {
    public:
        Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
        ~Vector3D() = default;

        double x;
        double y;
        double z;
};

#endif /* !VECTOR3D_HPP_ */

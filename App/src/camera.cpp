/*
** EPITECH PROJECT, 2024
** raytracer | Camera
** File description:
** camera.cpp
*/

#include "RayTracer/Scene/Camera.hpp"

rtr::Camera::Camera(uint16_t fov, const Vector &origin, const Vector &direction) : m_fov{fov}, m_origin{origin}, m_direction{direction}
{
    const double viewportHeight = 2.0 * tan(m_fov * M_PI / 180 / 2);
    const double viewportWidth = m_aspectRatio * viewportHeight;

    m_w = (origin - m_direction).normalize();
    m_u = {1, 0, 0};
    if (std::abs(getUp().dot(m_w)) == 1.0) {
        m_u = {1, 0, 0};
    } else {
        m_u = getUp().cross(m_w).normalize();
    }
    m_v = m_w.cross(m_u);

    m_horizontal = m_u * viewportWidth;
    m_vertical = m_v * viewportHeight;
    m_lowerLeftCorner = m_origin - m_horizontal / 2 - m_vertical / 2 - m_w;
}

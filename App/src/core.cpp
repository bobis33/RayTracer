/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Core.cpp
*/

#include <dlfcn.h>

#include "RayTracer/Core.hpp"
#include "RayTracer/Factory/RendererFactory.hpp"

void RayTracer::Core::runRayTracer(const Scene &scene)
{
    std::cout << "RayTracer is running" << '\n';

    m_renderer = RendererFactory::createRenderer("./plugins/raytracer_ppm_renderer.so");
    m_renderer->render(scene);
}

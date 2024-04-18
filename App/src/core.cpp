/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Core.cpp
*/

#include "RayTracer/Core.hpp"
#include "RayTracer/Factory/RendererFactory.hpp"
#include "RayTracer/Factory/ShapesFactory.hpp"

void RayTracer::Core::runRayTracer(const Scene &scene)
{
    std::cout << "RayTracer is running" << '\n';

    m_renderer = RendererFactory::createRenderer("./plugins/raytracer_ppm_renderer.so");
    m_renderer->render(scene);

    std::unique_ptr<AShapes> sphere1 = ShapesFactory::createShape(ShapeType::SPHERE, {0, 0, 0}, {255, 255, 255}, 0.0F);
}

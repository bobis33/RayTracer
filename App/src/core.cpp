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
    m_renderer = RendererFactory::createRenderer(RendererType::PPM);
    m_renderer->render(scene);

    std::unique_ptr<AShapes> sphere1 = ShapesFactory::createShape(ShapeType::SPHERE, {0, 0, 0}, {255, 255, 255}, 0.0F);
}

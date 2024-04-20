/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Core.cpp
*/

#include "RayTracer/Core.hpp"

#include "RayTracer/Factory/RendererFactory.hpp"

void RayTracer::Core::runRayTracer(const Scene &scene)
{
    m_renderer = RendererFactory::createRenderer(scene.getRendererType());

    if (!m_renderer) {
        throw CoreException{"Cannot create renderer"};
    }

    m_renderer->render(scene);

    // std::unique_ptr<AShapes> sphere1 = ShapesFactory::createShape(ShapeType::SPHERE, {0, 0, 0}, {255, 255, 255}, 4.0F);
}

/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "RayTracer/SfmlRenderer.hpp"

void RayTracer::SfmlRenderer::render(const Scene &scene)
{

    sf::RenderWindow window(sf::VideoMode(scene.getResolution().first, scene.getResolution().second), scene.getName());

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }

}

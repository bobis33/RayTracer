/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** renderer.cpp
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "RayTracer/SfmlRenderer.hpp"

void RayTracer::SfmlRenderer::render(const Scene &scene)
{
    setName(scene.getName());
    setResolution(scene.getResolution());

    sf::RenderWindow window(sf::VideoMode(getResolution().first, getResolution().second), getName());

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

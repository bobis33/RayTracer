/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "RayTracer/SFML.hpp"

void RayTracer::SFML::render()
{

    sf::RenderWindow window(sf::VideoMode(getResolution().getWidth(), getResolution().getWidth()), getName());

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

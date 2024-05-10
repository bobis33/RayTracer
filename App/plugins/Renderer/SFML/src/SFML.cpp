/*
** EPITECH PROJECT, 2024
** Raytracer | renderer
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "RayTracer/SFML.hpp"

void rtr::SFML::render(const std::vector<AShape*> &shapes, const std::vector<std::unique_ptr<ALight>> &lights, const Camera &camera)
{
    (void) shapes; (void) camera; (void) lights;
    sf::RenderWindow window(sf::VideoMode(getResolution().getWidth(), getResolution().getHeight()), getName());

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

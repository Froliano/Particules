#include <SFML/Graphics.hpp>
#include <iostream>
#include "ParticulesManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Particules");

    window.setFramerateLimit(60);
	
	ParticulesManager particulesManager;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                particulesManager.createParticule(event.mouseButton.x, event.mouseButton.y);
            }
        }

        window.clear(sf::Color::Black);
		particulesManager.update(window);
        window.display();
    }
}

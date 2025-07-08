#include "Particule.hpp"

void Particule::update(sf::RenderWindow& window) 
{
	position += velocity;
	shape.setPosition(position);
	window.draw(shape);
	lifeTime -= 0.1f;
}
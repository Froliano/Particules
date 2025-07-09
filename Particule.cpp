#include "Particule.hpp"

void Particule::update(sf::RenderWindow& window) 
{
	position += velocity;
	shape.setPosition(position);
	shape.setFillColor(color);
	window.draw(shape);
	lifeTime -= 0.1f;
}
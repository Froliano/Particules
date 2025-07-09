#include <SFML/Graphics.hpp>
#include <iostream>

class Particule {
private:
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	float lifeTime;
	float radius;
	int duplicationCount;


public:
	Particule(float x, float y, float vx, float vy, float life, float r, sf::Color color, int dupCount)
		: position(x, y), velocity(vx, vy), lifeTime(life), radius(r), color(color), duplicationCount(dupCount) {
		shape.setRadius(radius);
		shape.setPosition(position);
		shape.setFillColor(sf::Color::White);
	}
	void update(sf::RenderWindow& window);
	bool isAlive() const { return lifeTime > 0;}
	sf::Vector2f getPosition() const { return position; }
	int getDuplicationCount() const { return duplicationCount; }
	float getRadius() const { return radius; }
	sf::Color getColor() const { return color; }
};
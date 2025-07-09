#include <SFML/Graphics.hpp>
#include "Particule.hpp"
#include <random>

class ParticulesManager {
private:
	std::vector<Particule*> particules;


	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<> velocity;
	std::uniform_int_distribution<> lifeTime;
	std::uniform_int_distribution<> radius;
	std::uniform_int_distribution<> dupCount;
	std::uniform_int_distribution<> particulesCreate;
	std::uniform_int_distribution<> randomColor;

	sf::Vector2f normalize(sf::Vector2f vector);
	void duplicateParticule(Particule* particule);

public:
	ParticulesManager();
	void update(sf::RenderWindow& window);
	void createParticule(float x, float y);
	void createParticule(float x, float y, float r, sf::Color color, int duplicationCountValue);

};
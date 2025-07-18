#include "ParticulesManager.hpp"

ParticulesManager::ParticulesManager()
	: gen(rd()), velocity(-10, 10), lifeTime(5, 10), radius(150, 400), dupCount(0, 2), particulesCreate(3, 7), randomColor(0, 255)
{}

void ParticulesManager::update(sf::RenderWindow& window) {
	for (int i = 0; i < particules.size(); i++)
	{
		Particule* particule = particules[i];
		particule->update(window);
		if (!particule->isAlive())
		{
			duplicateParticule(particule);
			delete particule;
			particules.erase(particules.begin() + i);
		}
	}
}

void ParticulesManager::createParticule(float x, float y) {
	int particulesCount = particulesCreate(gen);

	for (int i = 0; i < particulesCount; i++)
	{
		sf::Vector2f randomVelocity = normalize(sf::Vector2f(velocity(gen), velocity(gen)));
		float lifeTimeValue = lifeTime(gen);
		float radiusValue = radius(gen) / 100;
		int duplicationCountValue = dupCount(gen);
		sf::Color color(randomColor(gen), randomColor(gen), randomColor(gen));

		particules.push_back(new Particule(x, y, randomVelocity.x, randomVelocity.y, lifeTimeValue, radiusValue, color, duplicationCountValue));
	}
	
}

void ParticulesManager::createParticule(float x, float y, float r, sf::Color color, int duplicationCountValue) {
	int particulesCount = particulesCreate(gen);

	for (int i = 0; i < particulesCount; i++)
	{
		sf::Vector2f randomVelocity = normalize(sf::Vector2f(velocity(gen), velocity(gen)));
		float lifeTimeValue = lifeTime(gen);

		particules.push_back(new Particule(x, y, randomVelocity.x, randomVelocity.y, lifeTimeValue, r, color, duplicationCountValue));
	}
	
}

sf::Vector2f ParticulesManager::normalize(sf::Vector2f vector)
{
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length == 0)
	{
		return normalize(sf::Vector2f(velocity(gen), velocity(gen)));
	}

	return sf::Vector2f(vector.x / length, vector.y / length);
}

void ParticulesManager::duplicateParticule(Particule* particule)
{
	int duplicateCount = particule->getDuplicationCount();
	sf::Vector2f particulePos = particule->getPosition();
	float parentRadius = particule->getRadius();
	sf::Color parentColor = particule->getColor();

	if (duplicateCount > 0)
	{
		createParticule(particulePos.x, particulePos.y, parentRadius, parentColor, duplicateCount -1);
	}
}

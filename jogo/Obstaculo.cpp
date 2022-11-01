#include "Obstaculo.h"

Obstaculo::Obstaculo()
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Floresta/Grama3.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.25, 0.10));
	sprite.setPosition(sf::Vector2f(300.f, 100.f));
}
Obstaculo::~Obstaculo()
{
}
void Obstaculo::setPosi(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}
#include "Espinhos.h"
Espinhos::Espinhos()
{
	danoso = true;
	if (!texture.loadFromFile("assets/Obstaculos/Floresta/espinhos.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.5, 0.25));
	sprite.setPosition(sf::Vector2f(300.f, 100.f));
}
Espinhos::~Espinhos()
{

}
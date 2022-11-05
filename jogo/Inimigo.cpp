#include "Inimigo.h"
Inimigo::Inimigo(): Entidade::Entidade()
{
	if (!texture.loadFromFile("assets/Inimigos/AtiradorSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(200.f, 200.f));
}
Inimigo::~Inimigo()
{

}
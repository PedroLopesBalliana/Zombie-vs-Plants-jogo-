#pragma once
#include "Arvore.h"

Arvore::Arvore() : Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/Ente.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(5, 5));
	sprite.setPosition(sf::Vector2f(500.f, 500.f));
}
Arvore::~Arvore()
{

}
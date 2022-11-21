#pragma once
#include "Arvore.h"

Arvore::Arvore() : Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/Arvore.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(0.5, 0.5));
	sprite.setPosition(sf::Vector2f(300.f, 300.f));
}
Arvore::~Arvore()
{

}
void Arvore::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
}
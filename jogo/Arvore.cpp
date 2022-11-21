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
	sprite.setPosition(sf::Vector2f(500.f, 525.f));
	facingLeft=false;
}
Arvore::~Arvore()
{

}
void Arvore::mover()
{
	if (sprite.getPosition().x < limEsq && !facingLeft)
	{
		facingLeft = true;
		sprite.move(sf::Vector2f(200.0f, 0.f));
		sprite.scale(-1, 1);
	}
	if (sprite.getPosition().x > limDir && facingLeft)
	{
		facingLeft = false;
		sprite.move(sf::Vector2f(-200.0f, 0.f));
		sprite.scale(-1, 1);
	}
	if (!facingLeft)
		sprite.move(sf::Vector2f(-3.0f, 0.f));
	else
		sprite.move(sf::Vector2f(3.0f, 0.f));
}
void Arvore::setLimites(float esq, float dir)
{
	limEsq = esq;
	limDir = dir;
}
void Arvore::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	mover();
}
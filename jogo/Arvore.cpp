#pragma once
#include "Arvore.h"

Arvore::Arvore() : Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/Arvoreee.png"))
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
	float aux;
	float centroX, centroY;
	sf::Vector2f posi;
	gravidade(deltaTempo);
	imprimirSe();
	aux = rand() % 500;
	if (rand() % 2)
	{
		aux = -aux;
	}
	maca->setForca(aux);
	centroX = sprite.getPosition().x + (sprite.getGlobalBounds().width / 2);
	centroY = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
	posi.x = centroX;
	posi.y = centroY;
	maca->executar(deltaTempo, posi);

}
void Arvore::setProjetil(Projetil* pr)
{
	maca = pr;
}
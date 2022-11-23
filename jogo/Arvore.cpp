#pragma once
#include "Arvore.h"

Arvore::Arvore() : Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/Arvoreee.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!envenenar.loadFromFile("assets/Inimigos/entespikes.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1.0, 1.0));
	sprite.setPosition(sf::Vector2f(300.f, 325.f));
	facingLeft=false;
	velocidadeV.y = 50.f;
	velocidade = 300.f;
}
Arvore::~Arvore()
{

}
void Arvore::pular()
{
	velocidadeV.y = -sqrtf(2.0f * 981.0f * 100.0f);
}
void Arvore::mover()
{
	if (sprite.getPosition().x < limEsq && !facingLeft)
	{
		facingLeft = true;
		//sprite.move(sf::Vector2f(200.0f, 0.f));
		//sprite.scale(-1, 1);
		//pular();
	}
	if (sprite.getPosition().x > limDir && facingLeft)
	{
		facingLeft = false;
		//sprite.move(sf::Vector2f(-200.0f, 0.f));
		//sprite.scale(-1, 1);
		//pular();
	}
	if (!facingLeft)
		sprite.move(sf::Vector2f(-3.0f, 0.f));
	else
		sprite.move(sf::Vector2f(3.0f, 0.f));
	if (sprite.getPosition().y > 325.f)
	{
		pular();
	}

}
void Arvore::setLimites(float esq, float dir)
{
	limEsq = esq;
	limDir = dir;
}
void Arvore::executar(float deltaTempo)
{
	float aux;
	float centroX, centroY;
	sf::Vector2f posi;
	gravidade(deltaTempo);
	imprimirSe();
	mover();
	sprite.move(velocidadeV * 0.01f);
	aux = rand() % 500;
	if (rand() % 2)
	{
		aux = -aux;
	}
	maca->setForca(aux);
	if (facingLeft)
	{
		centroX = sprite.getPosition().x - (sprite.getGlobalBounds().width / 2);
		centroY = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
	}
	else
	{
		centroX = sprite.getPosition().x + (sprite.getGlobalBounds().width / 2);
		centroY = sprite.getPosition().y + (sprite.getGlobalBounds().height / 2);
	}
	posi.x = centroX;
	posi.y = centroY;
	maca->executar(deltaTempo, posi);
		charge++;
	if (charge == 500)
	{
		sprite.setTexture(envenenar);
		Pedra::setVeneno(true);
		charge = 0;
	}
	if (charge == 100)
	{
		sprite.setTexture(texture);
		Pedra::setVeneno(false);
	}
}
void Arvore::setProjetil(Projetil* pr)
{
	maca = pr;
}

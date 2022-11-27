#pragma once
#include "Atirador.h"

Entidades::Personagens::Atirador::Atirador(): Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/AtiradorSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(1, 1));
	sprite.setPosition(sf::Vector2f(200.f, 150.f));
}
Entidades::Personagens::Atirador::~Atirador()
{

}
void Entidades::Personagens::Atirador::executar(const float deltaTempo)
{
	if (num_vidas > 0)
	{
		gravidade(deltaTempo);
		imprimirSe();
		mover();
		if (tipo == 1)
		{
			tiro->setForca(0.f);
			tiro->executar(deltaTempo);
		}
		else if(tipo == 2)
		{
			tiro->setForca(250.f);
			tiro->executar(deltaTempo);
		}
		else if (tipo == 3)
		{
			tiro->setForca(-250.f);
			tiro->executar(deltaTempo);
		}
	}
	else
	{
		sprite.move(sf::Vector2f(1000, 1000));
		tiro->setForca(-250.f);
		tiro->executar(deltaTempo);
	}
}
void Entidades::Personagens::Atirador::mover()
{
	if (tipo == 1)
	{
		if (sprite.getPosition().x < 100 && !facingLeft)
		{
			facingLeft = true;
			sprite.scale(-1, 1);
		}
		if (sprite.getPosition().x > 900 && facingLeft)
		{
			facingLeft = false;
			sprite.scale(-1, 1);
		}
		if (sprite.getPosition().y > 100 && !goingUp)
		{
			goingUp = true;
		}
		if (sprite.getPosition().y < 10 && goingUp)
		{
			goingUp = false;
		}
		if (!facingLeft)
			sprite.move(sf::Vector2f(-3.f, 0.f));
		else
			sprite.move(sf::Vector2f(3.f, 0.f));
		if (!goingUp)
			sprite.move(sf::Vector2f(0.f, 1.5f));
		else
			sprite.move(sf::Vector2f(0.f, -1.5f));
	}
	else if (tipo == 2 || tipo == 3)
	{
		if (sprite.getPosition().y > 600 && !goingUp)
		{
			goingUp = true;
		}
		if (sprite.getPosition().y < 100 && goingUp)
		{
			goingUp = false;
		}
		if (!goingUp)
			sprite.move(sf::Vector2f(0.f, 1.5f));
		else
			sprite.move(sf::Vector2f(0.f, -1.5f));
	}
}
void Entidades::Personagens::Atirador::setProjetil(Projetil* pr)
{
	tiro = pr;
}
void Entidades::Personagens::Atirador::danificar(Jogador* jog)
{
	jog->operator--();
	if (jog->getSentido())
		jog->corrigir(10.f, 10.f);
	else
		jog->corrigir(10.f, -10.f);
}

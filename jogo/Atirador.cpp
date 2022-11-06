#pragma once
#include "Atirador.h"

Atirador::Atirador(): Inimigo()
{
	if (!texture.loadFromFile("assets/Inimigos/AtiradorSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(200.f, 150.f));
}
Atirador::~Atirador()
{

}
void Atirador::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	mover();
	tiro->executar(deltaTempo, sprite.getPosition());
}
void Atirador::mover()
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
	if (sprite.getPosition().y > 200 && !goingUp)
	{
		goingUp = true;
	}
	if (sprite.getPosition().y < 100 && goingUp)
	{
		goingUp = false;
	}
	if (!facingLeft)
		sprite.move(sf::Vector2f(-0.1f, 0.f));
	else
		sprite.move(sf::Vector2f(0.1f, 0.f));
	if (!goingUp)
		sprite.move(sf::Vector2f(0.f, 0.05f));
	else
		sprite.move(sf::Vector2f(0.f, -0.05f));
}
void Atirador::setProjetil(Projetil* pr)
{
	tiro = pr;
}

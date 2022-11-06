#include "Inimigo.h"
Inimigo::Inimigo(): Entidade::Entidade(), facingLeft(true), goingUp(false)
{
	if (!texture.loadFromFile("assets/Inimigos/AtiradorSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(200.f, 150.f));
}
Inimigo::~Inimigo()
{

}
void Inimigo::gravidade(float deltaTempo)
{
	sprite.move(sf::Vector2f(0.f, 0.15f));
	flutua();
}
void Inimigo::flutua()
{
	sprite.move(sf::Vector2f(0.f, -0.15f));
}
void Inimigo::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	mover();
}
void Inimigo::mover()
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
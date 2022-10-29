#include "Jogador.h"
Jogador::Jogador() :Entidade()
{

}
Jogador::~Jogador()
{

}
void Jogador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		body.move(sf::Vector2f(0.1f, 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		body.move(sf::Vector2f(0.f, -0.1f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		body.move(sf::Vector2f(-0.1f, 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		body.move(sf::Vector2f(0.f, 0.1f));
	}
}
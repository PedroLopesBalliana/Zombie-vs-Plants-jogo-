#include "Jogador.h"
Jogador::Jogador() :Entidade()
{
	if (!texture.loadFromFile("assets/Zumbi_Jogador/zombieSprite.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2, 2));
	sprite.setPosition(sf::Vector2f(200.f, 200.f));
	facingLeft = true;
}
Jogador::~Jogador()
{
}
void Jogador::gravidade()
{
	sprite.move(sf::Vector2f(0.f, 0.3f));
}
void Jogador::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(sf::Vector2f(0.1f, 0.f));
		if (facingLeft)
		{
			sprite.scale(-1, 1);
			sprite.move(sf::Vector2f(50.0f, 0.f));
			facingLeft = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		sprite.move(sf::Vector2f(-0.1f, 0.f));
		if (!facingLeft)
		{
			sprite.move(sf::Vector2f(-50.0f, 0.0f));
			sprite.scale(-1, 1);
			sprite.move(sf::Vector2f(5.0f, 0.f));
			facingLeft = true;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(sf::Vector2f(0.f, -0.5f));
	}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // gravidade fake
	//{
	//	sprite.move(sf::Vector2f(0.f, 0.5f));
	//}
}
float Jogador::getY()
{
	return sprite.getPosition().y;
}
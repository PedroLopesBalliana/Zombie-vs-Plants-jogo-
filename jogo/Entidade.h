#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
namespace Entidades
{
	class Entidade
	{
	protected:
		sf::Texture texture;
		sf::Sprite sprite;
	public:
		Entidade();
		~Entidade();
		sf::Sprite getSprite();
		sf::Vector2f getFronteiras();
	};
}
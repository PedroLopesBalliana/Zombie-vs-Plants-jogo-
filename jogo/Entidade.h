#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ente.h"
namespace Entidades
{
	class Entidade : public Ente
	{
	protected:
	public:
		Entidade();
		~Entidade();
		sf::Sprite getSprite();
		sf::Vector2f getFronteiras();
	};
}
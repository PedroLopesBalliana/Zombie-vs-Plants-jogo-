#pragma once
#include <iostream>
#include "Ente.h"
	class Entidade : public Ente
	{
	protected:
	public:
		Entidade();
		~Entidade();
		sf::Sprite getSprite();
		sf::Vector2f getFronteiras();
	};
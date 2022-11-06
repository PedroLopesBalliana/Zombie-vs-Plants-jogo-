#pragma once
#include <iostream>
#include "Ente.h"
	class Entidade : public Ente
	{
	protected:
		sf::Vector2f velocidadeV;
		float velocidade;
	public:
		Entidade();
		~Entidade();
		sf::Sprite getSprite();
		sf::FloatRect getSpriteBounds();
		virtual void gravidade(float DeltaTempo);
		virtual void executar(float deltaTempo);
	};
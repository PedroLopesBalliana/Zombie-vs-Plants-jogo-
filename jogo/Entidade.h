#pragma once
#include <iostream>
#include "Ente.h"
namespace Entidades
{
	class Entidade : public Ente
	{
	protected:
		sf::Vector2f velocidadeV;
		float velocidade;
		const float gravid;
	public:
		Entidade();
		virtual ~Entidade();
		sf::Sprite getSprite();
		void scaleSprite(float x, float y);
		sf::FloatRect getSpriteBounds();
		virtual void gravidade(const float DeltaTempo);
		virtual void executar(const float deltaTempo);
		void setPosi(const float x, const float y);
		void setSpeed(const float v);
		virtual void danificar();
	};
}
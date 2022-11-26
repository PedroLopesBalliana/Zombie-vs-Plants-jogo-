#pragma once
#include <iostream>
#include "Ente.h"
	class Entidade : public Ente
	{
	protected:
		sf::Vector2f velocidadeV;
		float velocidade;
		static int pontuacao;
		float gravid;
	public:
		Entidade();
		~Entidade();
		sf::Sprite getSprite();
		void scaleSprite(float x, float y);
		sf::FloatRect getSpriteBounds();
		virtual void gravidade(float DeltaTempo);
		virtual void executar(float deltaTempo);
		void setPosi(float x, float y);
		void setSpeed(float v);
		int getPontuacao();
		virtual void danificar();
	};
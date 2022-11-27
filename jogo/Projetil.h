#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades
{
	class Projetil : public Entidade
	{
	private:
		float forca;
		sf::Texture maca;
	public:
		Projetil();
		~Projetil();
		void executar(const float deltaTempo, sf::Vector2f posicao);
		void setForca(float f);
		void setMaca();
		void danificar(Entidades::Personagens::Jogador* jog);
	};
}

#pragma once
#include "Jogador.h"
#include "Entidade.h"


namespace Entidades
{
	namespace Personagens
	{
		class Atirador;
	}
	class Projetil : public Entidade
	{
	private:
		float forca;
		sf::Texture maca;
		Personagens::Atirador* dono;
	public:
		Projetil(Personagens::Atirador* don);
		~Projetil();
		void executar(const float deltaTempo);
		void setForca(float f);
		void setMaca();
		void danificar(Entidades::Personagens::Jogador* jog);
	};
}

#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "Pedra.h"
#include "Atirador.h"
#include "Bulbassauro.h"
namespace Entidades
{
	namespace Personagens
	{
		class Arvore : public Atirador, public Bulbassauro
		{
		private:
			int charge;
			sf::Texture envenenar;
		public:
			Arvore();
			~Arvore();
			void executar(float deltaTempo);
			void pular();
			void mover();
			void operator--();
			void danificar(Jogador* jog);
		};
	}
}

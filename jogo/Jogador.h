#pragma once
#include "Personagem.h"
#include <windows.h>
namespace Entidades
{
	namespace Personagens
	{
		class Jogador :public Personagem
		{
		private:
			int charge;
			bool pulou;
			bool atacando;
			sf::Texture ataque;
			bool movimento;
			float pontos;
		public:
			Jogador();
			Jogador(bool movi);
			~Jogador();
			void move(float deltaTime);
			void corrigir(float height, float side);
			void executar(const float deltaTempo);
			void atacar();
			const bool getAtacando()const;
			const float getPontuacao() const;
			void incrementaPontos();
			const int getNumVidas() const;
			void operator--();
			void operator--(int dan);
		};
	}
}

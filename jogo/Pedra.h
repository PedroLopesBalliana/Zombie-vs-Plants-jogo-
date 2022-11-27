#pragma once
#include "Obstaculo.h"
namespace Entidades
{
	namespace Obstaculos
	{
		class Pedra : public Obstaculo
		{
		private:
			static bool envenenado;
			sf::Texture veneno;
		public:
			Pedra();
			~Pedra();
			void executar(const float deltaTempo);
			const float getTipo();
			static void setVeneno(const bool ven);
			void danificar(Entidades::Personagens::Jogador* jog);
		};
	}
}
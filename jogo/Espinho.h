#pragma once
#include "Obstaculo.h"


namespace Entidades
{
	namespace Obstaculos
	{
		class Espinho : public Obstaculo
		{
		private:
			float ferrao;
		public:
			Espinho();
			~Espinho();
			void executar(const float deltaTempo);
			const float getTipo();
			void danificar(Entidades::Personagens::Jogador* jog);
		};
	}
}

#pragma once
#include "Obstaculo.h"
namespace Entidades
{
	namespace Obstaculos
	{
		class Grama : public Obstaculo
		{
		private:
			float aderencia;
		public:
			Grama();
			~Grama();
			void executar(const float deltaTempo);
			const float getTipo();
			void danificar(Entidades::Personagens::Jogador* jog);
		};
	}
}

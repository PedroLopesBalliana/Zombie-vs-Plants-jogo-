#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades
{
	namespace Obstaculos
	{
		class Obstaculo : public Entidade
		{
		protected:
			bool danoso;
		public:
			Obstaculo();
			virtual ~Obstaculo();
			virtual void flutua(float deltaTempo);
			virtual void executar(const float deltaTempo);
			virtual bool getDanoso();
			virtual const float getTipo();
			virtual void danificar(Entidades::Personagens::Jogador* jog) = 0;
		};
	}
}

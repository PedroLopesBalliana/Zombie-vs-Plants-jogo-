#pragma once
#include "Inimigo.h"
namespace Entidades
{
	namespace Personagens
	{
		class Bulbassauro : virtual public Inimigo
		{
		protected:
			float raiva;
			float limEsq;
			float limDir;
		public:
			Bulbassauro();
			~Bulbassauro();
			virtual void executar(float deltaTempo);
			virtual void setLimites(const float esq, const float dir);
			virtual void mover();
			virtual void danificar(Jogador* jog);
		};
	}
}

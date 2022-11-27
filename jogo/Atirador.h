#pragma once
#include "Inimigo.h"
#include "Projetil.h"
namespace Entidades
{
	namespace Personagens
	{
		class Atirador : virtual public Inimigo
		{
		protected:
			Projetil* tiro;
		public:
			Atirador();
			~Atirador();
			virtual void executar(float deltaTempo);
			virtual void mover();
			virtual void danificar(Jogador* jog);
			void setProjetil(Projetil* pr);
		};
	}
}
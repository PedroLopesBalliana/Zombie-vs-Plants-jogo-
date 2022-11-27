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
			Entidades::Projetil* tiro;
		public:
			Atirador();
			~Atirador();
			virtual void executar(float deltaTempo);
			virtual void mover();
			virtual void danificar(Jogador* jog);
			void setProjetil(Entidades::Projetil* pr);
		};
	}
}
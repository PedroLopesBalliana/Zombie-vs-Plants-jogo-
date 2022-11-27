#pragma once
#include "Personagem.h"
#include "Projetil.h"
#include "Jogador.h"

namespace Entidades
{
	namespace Personagens
	{
		class Inimigo : public Personagem
		{
		private:
		protected:
			static int quant;
			bool goingUp;
			int tipo;
		public:
			Inimigo();
			virtual ~Inimigo();
			virtual void flutua();
			virtual void executar(const float deltaTempo);
			virtual void mover();
			void setTipo(int ti);
			static int getQuant();
			void operator--();
			virtual void danificar(Jogador* jog) = 0;
	};
}	
}

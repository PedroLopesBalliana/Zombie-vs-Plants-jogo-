#pragma once
#include "Entidade.h"
#include <windows.h>

namespace Entidades
{
	namespace Personagens
	{
		class Personagem :public Entidade
		{
		protected:
			bool facingLeft;
			int num_vidas;
		public:
			Personagem();
			~Personagem();
			virtual void move(float deltaTime);
			virtual void executar(const float deltaTempo);
			bool getSentido();
			virtual void operator--();
		};
	}
}

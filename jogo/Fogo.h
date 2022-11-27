#include "Obstaculo.h"
namespace Entidades
{
	namespace Obstaculos
	{
		class Fogo : public Obstaculo
		{
		private:
			float labareda;
		public:
			Fogo();
			~Fogo();
			void executar(const float deltaTempo);
			const float getTipo();
			void danificar(Entidades::Personagens::Jogador* jog);
		};
	}
}
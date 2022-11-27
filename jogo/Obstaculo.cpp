#include "Obstaculo.h"


Entidades::Obstaculos::Obstaculo::Obstaculo(): danoso(false)
{
	
}
Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}
void Entidades::Obstaculos::Obstaculo::flutua(float deltaTempo)
{
	velocidadeV.y -= 981.0f * deltaTempo;
}
void Entidades::Obstaculos::Obstaculo::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
}
bool Entidades::Obstaculos::Obstaculo::getDanoso()
{
	return danoso;
}
const float Entidades::Obstaculos::Obstaculo::getTipo()
{
	return 1;
}
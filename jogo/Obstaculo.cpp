#include "Obstaculo.h"

Obstaculo::Obstaculo(): danoso(false)
{
	
}
Obstaculo::~Obstaculo()
{
}
void Obstaculo::flutua(float deltaTempo)
{
	velocidadeV.y -= 981.0f * deltaTempo;
}
void Obstaculo::executar(float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
}
bool Obstaculo::getDanoso()
{
	return danoso;
}
int Obstaculo::getTipo()
{
	return 1;
}
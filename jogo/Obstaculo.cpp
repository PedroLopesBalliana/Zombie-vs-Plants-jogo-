#include "Obstaculo.h"

Obstaculo::Obstaculo(): danoso(false)
{
	
}
Obstaculo::~Obstaculo()
{
}
void Obstaculo::setPosi(float x, float y)
{
	sprite.setPosition(sf::Vector2f(x, y));
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
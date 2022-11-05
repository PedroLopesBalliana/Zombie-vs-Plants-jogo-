#include "Ente.h"

Ente::Ente() : geren_graf(NULL)
{
}
Ente::~Ente()
{

}
void Ente::executar()
{
}
void Ente::imprimirSe()
{
	geren_graf->desenharEntidades(sprite);
}
void Ente::setGerenciadorGrafico(GerenciadorGrafico* gR)
{
	geren_graf = gR;
}
sf::Sprite Ente::getSprite()
{
	return sprite;
}
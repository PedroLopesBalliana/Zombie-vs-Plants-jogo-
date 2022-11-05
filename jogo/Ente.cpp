#include "Ente.h"

Ente::Ente()
{
	sprite.setPosition(sf::Vector2f(100.f, 100.f));
}
Ente::~Ente()
{

}
void Ente::executar()
{
	this->imprimirSe();
}
void Ente::imprimirSe()
{
	geren_graf->desenharEntidades(sprite);
}
void Ente::setGerenciadorGrafico(GerenciadorGrafico* gR)
{
	geren_graf = gR;
}
#include "Ente.h"

Ente::Ente(): id(0)
{
}
Ente::~Ente()
{
	geren_graf = nullptr;
}
void Ente::executar()
{
}
void Ente::imprimirSe()
{
	geren_graf->desenharEntidades(sprite);
}
void Ente::setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico* gR)
{
	geren_graf = gR;
}
sf::Sprite Ente::getSprite() const
{
	return sprite;
}
Gerenciadores::GerenciadorGrafico* Ente::geren_graf = NULL;
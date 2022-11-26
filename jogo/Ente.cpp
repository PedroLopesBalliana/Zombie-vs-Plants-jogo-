#include "Ente.h"

Ente::Ente() 
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
void Ente::setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico* gR)
{
	geren_graf = gR;
}
sf::Sprite Ente::getSprite() const
{
	return sprite;
}
Gerenciadores::GerenciadorGrafico* Ente::geren_graf = NULL;
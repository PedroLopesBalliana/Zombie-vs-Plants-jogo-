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
}
void Ente::imprimirSe()
{
	geren_graf->desenharEntidades(getSprite());
}
void Ente::setGerenciadorGrafico(GerenciadorGrafico* gR)
{
	geren_graf = gR;
}
sf::Sprite Ente::getSprite()
{
	return sprite;
}
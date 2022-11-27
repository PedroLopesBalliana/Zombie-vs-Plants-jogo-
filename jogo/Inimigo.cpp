#include "Inimigo.h"
Entidades::Personagens::Inimigo::Inimigo(): Personagem(), goingUp(false), tipo(0)
{
	num_vidas = 1;
	quant++;
}
Entidades::Personagens::Inimigo::~Inimigo()
{

}
void Entidades::Personagens::Inimigo::flutua()
{
	sprite.move(sf::Vector2f(0.f, -0.15f));
}
void Entidades::Personagens::Inimigo::executar(const float deltaTempo)
{

}
void Entidades::Personagens::Inimigo::mover()
{
	
}
void Entidades::Personagens::Inimigo::setTipo(int ti)
{
	tipo = ti;
}
int Entidades::Personagens::Inimigo::getQuant()
{
	return quant;
}
void Entidades::Personagens::Inimigo::operator--()
{
	num_vidas--;
	quant--;
}
int Entidades::Personagens::Inimigo::quant = 0;

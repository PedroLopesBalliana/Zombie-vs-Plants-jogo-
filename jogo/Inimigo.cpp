#include "Inimigo.h"
Inimigo::Inimigo(): Personagem(), goingUp(false), tipo(0)
{
	num_vidas = 1;
	quant++;
}
Inimigo::~Inimigo()
{

}
void Inimigo::flutua()
{
	sprite.move(sf::Vector2f(0.f, -0.15f));
}
void Inimigo::executar(float deltaTempo)
{
	//flutua();
}
void Inimigo::mover(int tipo)
{
	
}
void Inimigo::setTipo(int ti)
{
	tipo = ti;
}
int Inimigo::getQuant()
{
	return quant;
}
void Inimigo::operator--()
{
	num_vidas--;
	quant--;
	pontuacao = pontuacao + 1000;
}
int Inimigo::quant = 0;

#include "Inimigo.h"
Inimigo::Inimigo(): Personagem()
{

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
	flutua();
}
void Inimigo::mover()
{
	
}
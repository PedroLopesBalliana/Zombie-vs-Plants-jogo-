#include "Inimigo.h"
Inimigo::Inimigo(): Personagem(), goingUp(false)
{
	num_vidas = 1;
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
void Inimigo::setTipo(int ti)
{
	tipo = ti;
}
#include "Personagem.h"

Personagem::Personagem(): Entidade()
{

}
Personagem::~Personagem()
{

}
void Personagem::move(float deltaTempo)
{

}
void Personagem::executar(float deltaTempo)
{

}
bool Personagem::getSentido()
{
	return facingLeft;
}
void Personagem::operator--()
{
	num_vidas--;
	printf(" personagem vida %d \n", num_vidas);
}
#include "Personagem.h"

Entidades::Personagens::Personagem::Personagem(): Entidade()
{

}
Entidades::Personagens::Personagem::~Personagem()
{

}
void Entidades::Personagens::Personagem::move(float deltaTempo)
{

}
void Entidades::Personagens::Personagem::executar(float deltaTempo)
{

}
bool Entidades::Personagens::Personagem::getSentido()
{
	return facingLeft;
}
void Entidades::Personagens::Personagem::operator--()
{
	num_vidas--;
	//printf(" personagem vida %d \n", num_vidas);
}
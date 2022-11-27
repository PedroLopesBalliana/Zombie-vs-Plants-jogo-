#pragma once
#include "Pedra.h"

Entidades::Obstaculos::Pedra::Pedra()
{
	if (!texture.loadFromFile("assets/Bloco_Texturas/Dungeon/Pedra2.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	if (!veneno.loadFromFile("assets/Bloco_Texturas/Dungeon/greenstone.png"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.scale(0.2f, 0.2f);
}
Entidades::Obstaculos::Pedra::~Pedra()
{

}
void Entidades::Obstaculos::Pedra::executar(const float deltaTempo)
{
	gravidade(deltaTempo);
	imprimirSe();
	flutua(deltaTempo);
	if (envenenado && danoso == false)
	{
		sprite.setTexture(veneno);
		danoso = true;
	}
	if (!envenenado)
	{
		sprite.setTexture(texture);
		danoso = false;
	}
}
const float Entidades::Obstaculos::Pedra::getTipo()
{
	return envenenado;
}
void Entidades::Obstaculos::Pedra::setVeneno(bool ven)
{
	envenenado = ven;
}
void Entidades::Obstaculos::Pedra::danificar(Entidades::Personagens::Jogador* jog)
{
	if (danoso)
	{
		jog->operator--();
		jog->corrigir(10.f, 0.f);
	}
}
bool Entidades::Obstaculos::Pedra::envenenado = false;
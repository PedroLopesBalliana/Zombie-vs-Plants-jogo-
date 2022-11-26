#pragma once
#include "Pedra.h"

Pedra::Pedra()
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
Pedra::~Pedra()
{

}
void Pedra::executar(float deltaTempo)
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
int Pedra::getTipo()
{
	return envenenado;
}
void Pedra::setVeneno(bool ven)
{
	envenenado = ven;
}
void Pedra::danificar(Jogador* jog)
{
	if (danoso)
	{
		jog->operator--();
		jog->corrigir(10.f, 0.f);
	}
}
bool Pedra::envenenado = false;